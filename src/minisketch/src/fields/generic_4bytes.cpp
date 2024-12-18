/**********************************************************************
 * Copyright (c) 2018 Pieter Wuille, Greg Maxwell, Gleb Naumenko      *
 * Distributed under the MIT software license, see the accompanying   *
 * file LICENSE or http://www.opensource.org/licenses/mit-license.php.*
 **********************************************************************/

/* This file was substantially auto-generated by doc/gen_params.sage. */
#include "../fielddefines.h"

#if defined(ENABLE_FIELD_BYTES_INT_4)

#include "generic_common_impl.h"

#include "../lintrans.h"
#include "../sketch_impl.h"

#endif

#include "../sketch.h"

namespace {
#ifdef ENABLE_FIELD_INT_25
// 25 bit field
typedef RecLinTrans<uint32_t, 5, 5, 5, 5, 5> StatTable25;
typedef RecLinTrans<uint32_t, 4, 4, 4, 4, 3, 3, 3> DynTable25;
constexpr StatTable25 SQR_TABLE_25({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x12, 0x48, 0x120, 0x480, 0x1200, 0x4800, 0x12000, 0x48000, 0x120000, 0x480000, 0x1200000, 0x800012});
constexpr StatTable25 QRT_TABLE_25({0, 0x482110, 0x482112, 0x1b3c3e6, 0x482116, 0x4960ae, 0x1b3c3ee, 0x4088, 0x482106, 0x58a726, 0x49608e, 0x5ce52e, 0x1b3c3ae, 0x2006, 0x4008, 0x1c1a8, 0x482006, 0x1e96488, 0x58a526, 0x400000, 0x49648e, 0x1800006, 0x5ced2e, 0xb3d3a8, 0x1b3d3ae});
typedef Field<uint32_t, 25, 9, StatTable25, DynTable25, &SQR_TABLE_25, &QRT_TABLE_25> Field25;
#endif

#ifdef ENABLE_FIELD_INT_26
// 26 bit field
typedef RecLinTrans<uint32_t, 6, 5, 5, 5, 5> StatTable26;
typedef RecLinTrans<uint32_t, 4, 4, 4, 4, 4, 3, 3> DynTable26;
constexpr StatTable26 SQR_TABLE_26({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x1b, 0x6c, 0x1b0, 0x6c0, 0x1b00, 0x6c00, 0x1b000, 0x6c000, 0x1b0000, 0x6c0000, 0x1b00000, 0x2c0001b, 0x300005a});
constexpr StatTable26 QRT_TABLE_26({0x217b530, 0x2ae82a8, 0x2ae82aa, 0x2001046, 0x2ae82ae, 0x2de032e, 0x200104e, 0x70c10c, 0x2ae82be, 0x20151f2, 0x2de030e, 0xbc1400, 0x200100e, 0x178570, 0x70c18c, 0x2ae4232, 0x2ae83be, 0x211d742, 0x20153f2, 0x21f54f2, 0x2de070e, 0x5e0700, 0xbc1c00, 0x3abb97e, 0x200000e, 0});
typedef Field<uint32_t, 26, 27, StatTable26, DynTable26, &SQR_TABLE_26, &QRT_TABLE_26> Field26;
#endif

#ifdef ENABLE_FIELD_INT_27
// 27 bit field
typedef RecLinTrans<uint32_t, 6, 6, 5, 5, 5> StatTable27;
typedef RecLinTrans<uint32_t, 4, 4, 4, 4, 4, 4, 3> DynTable27;
constexpr StatTable27 SQR_TABLE_27({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x4e, 0x138, 0x4e0, 0x1380, 0x4e00, 0x13800, 0x4e000, 0x138000, 0x4e0000, 0x1380000, 0x4e00000, 0x380004e, 0x600011f});
constexpr StatTable27 QRT_TABLE_27({0x6bf0530, 0x2be4496, 0x2be4494, 0x2bf0522, 0x2be4490, 0x1896cca, 0x2bf052a, 0x408a, 0x2be4480, 0x368ae72, 0x1896cea, 0x18d2ee0, 0x2bf056a, 0x1c76d6a, 0x400a, 0x336e9f8, 0x2be4580, 0x36baf12, 0x368ac72, 0x430360, 0x18968ea, 0x34a6b80, 0x18d26e0, 0xbf1560, 0x2bf156a, 0, 0x1c74d6a});
typedef Field<uint32_t, 27, 39, StatTable27, DynTable27, &SQR_TABLE_27, &QRT_TABLE_27> Field27;
#endif

#ifdef ENABLE_FIELD_INT_28
// 28 bit field
typedef RecLinTrans<uint32_t, 6, 6, 6, 5, 5> StatTable28;
typedef RecLinTrans<uint32_t, 4, 4, 4, 4, 4, 4, 4> DynTable28;
constexpr StatTable28 SQR_TABLE_28({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x3, 0xc, 0x30, 0xc0, 0x300, 0xc00, 0x3000, 0xc000, 0x30000, 0xc0000, 0x300000, 0xc00000, 0x3000000, 0xc000000});
constexpr StatTable28 QRT_TABLE_28({0x121d57a, 0x40216, 0x40214, 0x8112578, 0x40210, 0x10110, 0x8112570, 0x12597ec, 0x40200, 0x6983e00, 0x10130, 0x972b99c, 0x8112530, 0x8002000, 0x125976c, 0x815a76c, 0x40300, 0x936b29c, 0x6983c00, 0x97bb8ac, 0x10530, 0x9103000, 0x972b19c, 0xf6384ac, 0x8113530, 0x4113530, 0x8000000, 0});
typedef Field<uint32_t, 28, 3, StatTable28, DynTable28, &SQR_TABLE_28, &QRT_TABLE_28> Field28;
#endif

#ifdef ENABLE_FIELD_INT_29
// 29 bit field
typedef RecLinTrans<uint32_t, 6, 6, 6, 6, 5> StatTable29;
typedef RecLinTrans<uint32_t, 4, 4, 4, 4, 4, 3, 3, 3> DynTable29;
constexpr StatTable29 SQR_TABLE_29({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0xa, 0x28, 0xa0, 0x280, 0xa00, 0x2800, 0xa000, 0x28000, 0xa0000, 0x280000, 0xa00000, 0x2800000, 0xa000000, 0x8000005});
constexpr StatTable29 QRT_TABLE_29({0x1b8351dc, 0xb87135e, 0xb87135c, 0xda7b35e, 0xb871358, 0x621a116, 0xda7b356, 0x40200, 0xb871348, 0xc9e2620, 0x621a136, 0x478b16, 0xda7b316, 0x6762e20, 0x40280, 0x6202000, 0xb871248, 0x627a316, 0xc9e2420, 0xcd1ad36, 0x621a536, 0x760e20, 0x478316, 0xa760e20, 0xda7a316, 0x8000000, 0x6760e20, 0, 0x44280});
typedef Field<uint32_t, 29, 5, StatTable29, DynTable29, &SQR_TABLE_29, &QRT_TABLE_29> Field29;
#endif

#ifdef ENABLE_FIELD_INT_30
// 30 bit field
typedef RecLinTrans<uint32_t, 6, 6, 6, 6, 6> StatTable30;
typedef RecLinTrans<uint32_t, 4, 4, 4, 4, 4, 4, 3, 3> DynTable30;
constexpr StatTable30 SQR_TABLE_30({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x3, 0xc, 0x30, 0xc0, 0x300, 0xc00, 0x3000, 0xc000, 0x30000, 0xc0000, 0x300000, 0xc00000, 0x3000000, 0xc000000, 0x30000000});
constexpr StatTable30 QRT_TABLE_30({0x2159df4a, 0x109134a, 0x1091348, 0x10114, 0x109134c, 0x3a203420, 0x1011c, 0x20004080, 0x109135c, 0x2005439c, 0x3a203400, 0x100400, 0x1015c, 0x3eb21930, 0x20004000, 0x20504c00, 0x109125c, 0x3b2b276c, 0x2005419c, 0x210450c0, 0x3a203000, 0x3e93186c, 0x100c00, 0x3aa23530, 0x1115c, 0x6b3286c, 0x3eb23930, 0xeb23930, 0x20000000, 0});
typedef Field<uint32_t, 30, 3, StatTable30, DynTable30, &SQR_TABLE_30, &QRT_TABLE_30> Field30;
#endif

#ifdef ENABLE_FIELD_INT_31
// 31 bit field
typedef RecLinTrans<uint32_t, 6, 5, 5, 5, 5, 5> StatTable31;
typedef RecLinTrans<uint32_t, 4, 4, 4, 4, 4, 4, 4, 3> DynTable31;
constexpr StatTable31 SQR_TABLE_31({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x12, 0x48, 0x120, 0x480, 0x1200, 0x4800, 0x12000, 0x48000, 0x120000, 0x480000, 0x1200000, 0x4800000, 0x12000000, 0x48000000, 0x20000012});
constexpr StatTable31 QRT_TABLE_31({0, 0x10110, 0x10112, 0x15076e, 0x10116, 0x117130e, 0x150766, 0x4743fa0, 0x10106, 0x1121008, 0x117132e, 0x176b248e, 0x150726, 0x172a2c88, 0x4743f20, 0x7eb81e86, 0x10006, 0x20008, 0x1121208, 0x56b2c8e, 0x117172e, 0x133f1bae, 0x176b2c8e, 0x7f2a0c8e, 0x151726, 0x10000000, 0x172a0c88, 0x60000006, 0x4747f20, 0x3eb89e80, 0x7eb89e86});
typedef Field<uint32_t, 31, 9, StatTable31, DynTable31, &SQR_TABLE_31, &QRT_TABLE_31> Field31;
#endif

#ifdef ENABLE_FIELD_INT_32
// 32 bit field
typedef RecLinTrans<uint32_t, 6, 6, 5, 5, 5, 5> StatTable32;
typedef RecLinTrans<uint32_t, 4, 4, 4, 4, 4, 4, 4, 4> DynTable32;
constexpr StatTable32 SQR_TABLE_32({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x8d, 0x234, 0x8d0, 0x2340, 0x8d00, 0x23400, 0x8d000, 0x234000, 0x8d0000, 0x2340000, 0x8d00000, 0x23400000, 0x8d000000, 0x3400011a, 0xd0000468, 0x40001037});
constexpr StatTable32 QRT_TABLE_32({0x54fd1264, 0xc26fcd64, 0xc26fcd66, 0x238a7462, 0xc26fcd62, 0x973bccaa, 0x238a746a, 0x77766712, 0xc26fcd72, 0xc1bdd556, 0x973bcc8a, 0x572a094c, 0x238a742a, 0xb693be84, 0x77766792, 0x9555c03e, 0xc26fcc72, 0x568419f8, 0xc1bdd756, 0x96c3d2ca, 0x973bc88a, 0x54861fdc, 0x572a014c, 0xb79badc4, 0x238a642a, 0xb9b99fe0, 0xb6939e84, 0xc519fa86, 0x77762792, 0, 0x9555403e, 0x377627ba});
typedef Field<uint32_t, 32, 141, StatTable32, DynTable32, &SQR_TABLE_32, &QRT_TABLE_32> Field32;
#endif
}

Sketch* ConstructGeneric4Bytes(int bits, int implementation)
{
    switch (bits) {
#ifdef ENABLE_FIELD_INT_25
    case 25: return new SketchImpl<Field25>(implementation, 25);
#endif
#ifdef ENABLE_FIELD_INT_26
    case 26: return new SketchImpl<Field26>(implementation, 26);
#endif
#ifdef ENABLE_FIELD_INT_27
    case 27: return new SketchImpl<Field27>(implementation, 27);
#endif
#ifdef ENABLE_FIELD_INT_28
    case 28: return new SketchImpl<Field28>(implementation, 28);
#endif
#ifdef ENABLE_FIELD_INT_29
    case 29: return new SketchImpl<Field29>(implementation, 29);
#endif
#ifdef ENABLE_FIELD_INT_30
    case 30: return new SketchImpl<Field30>(implementation, 30);
#endif
#ifdef ENABLE_FIELD_INT_31
    case 31: return new SketchImpl<Field31>(implementation, 31);
#endif
#ifdef ENABLE_FIELD_INT_32
    case 32: return new SketchImpl<Field32>(implementation, 32);
#endif
    default: return nullptr;
    }
}
