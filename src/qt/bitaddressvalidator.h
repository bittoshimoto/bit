// Copyright (c) 2011-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BIT_QT_BITADDRESSVALIDATOR_H
#define BIT_QT_BITADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BitAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Bit address widget validator, checks for a valid bit address.
 */
class BitAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // BIT_QT_BITADDRESSVALIDATOR_H
