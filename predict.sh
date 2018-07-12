#!/bin/bash

target=000000000004a000000000000000000000000000000000000000000000000000
height=$(./komodo-cli -ac_name=VRSC getblocktemplate | jq .height)
echo Solving height: $height
echo Predict interval: $((height+0))..$((height+99))

utxos=$(./komodo-cli -ac_name=VRSC listunspent 0 9999999)
echo $utxos | jq '.[] | select (.spendable == true and .confirmations > 150)  | [.txid,.vout,(.amount * 100000000)]'  | jq -r '. | @csv' > listunspent.csv
OLDIFS=$IFS
IFS=","

for (( i=$((height+0)); i <= $((height+99)); i++ ))
do
while read txid vout amount; do
    txid=$(echo $txid | tr -d '"')
    echo -n "i.$i txid: $txid vout: $vout amount: $amount - Winner: "
    ./bin/Release/verus_vanga $txid $vout $i $amount $target 2>/dev/null | jq .result
    #./bin/Release/verus_vanga $txid $vout $i $amount $target | jq .result
done < listunspent.csv
done
IFS=$OLDIFS