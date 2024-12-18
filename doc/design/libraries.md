# Libraries

| Name                     | Description |
|--------------------------|-------------|
| *libbit_cli*         | RPC client functionality used by *bit-cli* executable |
| *libbit_common*      | Home for common functionality shared by different executables and libraries. Similar to *libbit_util*, but higher-level (see [Dependencies](#dependencies)). |
| *libbit_consensus*   | Stable, backwards-compatible consensus functionality used by *libbit_node* and *libbit_wallet* and also exposed as a [shared library](../shared-libraries.md). |
| *libbitconsensus*    | Shared library build of static *libbit_consensus* library |
| *libbit_kernel*      | Consensus engine and support library used for validation by *libbit_node* and also exposed as a [shared library](../shared-libraries.md). |
| *libbitqt*           | GUI functionality used by *bit-qt* and *bit-gui* executables |
| *libbit_ipc*         | IPC functionality used by *bit-node*, *bit-wallet*, *bit-gui* executables to communicate when [`--enable-multiprocess`](multiprocess.md) is used. |
| *libbit_node*        | P2P and RPC server functionality used by *bitd* and *bit-qt* executables. |
| *libbit_util*        | Home for common functionality shared by different executables and libraries. Similar to *libbit_common*, but lower-level (see [Dependencies](#dependencies)). |
| *libbit_wallet*      | Wallet functionality used by *bitd* and *bit-wallet* executables. |
| *libbit_wallet_tool* | Lower-level wallet functionality used by *bit-wallet* executable. |
| *libbit_zmq*         | [ZeroMQ](../zmq.md) functionality used by *bitd* and *bit-qt* executables. |

## Conventions

- Most libraries are internal libraries and have APIs which are completely unstable! There are few or no restrictions on backwards compatibility or rules about external dependencies. Exceptions are *libbit_consensus* and *libbit_kernel* which have external interfaces documented at [../shared-libraries.md](../shared-libraries.md).

- Generally each library should have a corresponding source directory and namespace. Source code organization is a work in progress, so it is true that some namespaces are applied inconsistently, and if you look at [`libbit_*_SOURCES`](../../src/Makefile.am) lists you can see that many libraries pull in files from outside their source directory. But when working with libraries, it is good to follow a consistent pattern like:

  - *libbit_node* code lives in `src/node/` in the `node::` namespace
  - *libbit_wallet* code lives in `src/wallet/` in the `wallet::` namespace
  - *libbit_ipc* code lives in `src/ipc/` in the `ipc::` namespace
  - *libbit_util* code lives in `src/util/` in the `util::` namespace
  - *libbit_consensus* code lives in `src/consensus/` in the `Consensus::` namespace

## Dependencies

- Libraries should minimize what other libraries they depend on, and only reference symbols following the arrows shown in the dependency graph below:

<table><tr><td>

```mermaid

%%{ init : { "flowchart" : { "curve" : "basis" }}}%%

graph TD;

bit-cli[bit-cli]-->libbit_cli;

bitd[bitd]-->libbit_node;
bitd[bitd]-->libbit_wallet;

bit-qt[bit-qt]-->libbit_node;
bit-qt[bit-qt]-->libbitqt;
bit-qt[bit-qt]-->libbit_wallet;

bit-wallet[bit-wallet]-->libbit_wallet;
bit-wallet[bit-wallet]-->libbit_wallet_tool;

libbit_cli-->libbit_util;
libbit_cli-->libbit_common;

libbit_common-->libbit_consensus;
libbit_common-->libbit_util;

libbit_kernel-->libbit_consensus;
libbit_kernel-->libbit_util;

libbit_node-->libbit_consensus;
libbit_node-->libbit_kernel;
libbit_node-->libbit_common;
libbit_node-->libbit_util;

libbitqt-->libbit_common;
libbitqt-->libbit_util;

libbit_wallet-->libbit_common;
libbit_wallet-->libbit_util;

libbit_wallet_tool-->libbit_wallet;
libbit_wallet_tool-->libbit_util;

classDef bold stroke-width:2px, font-weight:bold, font-size: smaller;
class bit-qt,bitd,bit-cli,bit-wallet bold
```
</td></tr><tr><td>

**Dependency graph**. Arrows show linker symbol dependencies. *Consensus* lib depends on nothing. *Util* lib is depended on by everything. *Kernel* lib depends only on consensus and util.

</td></tr></table>

- The graph shows what _linker symbols_ (functions and variables) from each library other libraries can call and reference directly, but it is not a call graph. For example, there is no arrow connecting *libbit_wallet* and *libbit_node* libraries, because these libraries are intended to be modular and not depend on each other's internal implementation details. But wallet code is still able to call node code indirectly through the `interfaces::Chain` abstract class in [`interfaces/chain.h`](../../src/interfaces/chain.h) and node code calls wallet code through the `interfaces::ChainClient` and `interfaces::Chain::Notifications` abstract classes in the same file. In general, defining abstract classes in [`src/interfaces/`](../../src/interfaces/) can be a convenient way of avoiding unwanted direct dependencies or circular dependencies between libraries.

- *libbit_consensus* should be a standalone dependency that any library can depend on, and it should not depend on any other libraries itself.

- *libbit_util* should also be a standalone dependency that any library can depend on, and it should not depend on other internal libraries.

- *libbit_common* should serve a similar function as *libbit_util* and be a place for miscellaneous code used by various daemon, GUI, and CLI applications and libraries to live. It should not depend on anything other than *libbit_util* and *libbit_consensus*. The boundary between _util_ and _common_ is a little fuzzy but historically _util_ has been used for more generic, lower-level things like parsing hex, and _common_ has been used for bit-specific, higher-level things like parsing base58. The difference between util and common is mostly important because *libbit_kernel* is not supposed to depend on *libbit_common*, only *libbit_util*. In general, if it is ever unclear whether it is better to add code to *util* or *common*, it is probably better to add it to *common* unless it is very generically useful or useful particularly to include in the kernel.


- *libbit_kernel* should only depend on *libbit_util* and *libbit_consensus*.

- The only thing that should depend on *libbit_kernel* internally should be *libbit_node*. GUI and wallet libraries *libbitqt* and *libbit_wallet* in particular should not depend on *libbit_kernel* and the unneeded functionality it would pull in, like block validation. To the extent that GUI and wallet code need scripting and signing functionality, they should be get able it from *libbit_consensus*, *libbit_common*, and *libbit_util*, instead of *libbit_kernel*.

- GUI, node, and wallet code internal implementations should all be independent of each other, and the *libbitqt*, *libbit_node*, *libbit_wallet* libraries should never reference each other's symbols. They should only call each other through [`src/interfaces/`](`../../src/interfaces/`) abstract interfaces.

## Work in progress

- Validation code is moving from *libbit_node* to *libbit_kernel* as part of [The libbitkernel Project #24303](https://github.com/bit/bit/issues/24303)
- Source code organization is discussed in general in [Library source code organization #15732](https://github.com/bit/bit/issues/15732)
