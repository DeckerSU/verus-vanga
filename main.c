#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef _WIN32
#include <sys/time.h>
#endif // !_WIN32
#include <stdint.h>
#include <ctype.h>

#include "haraka.h"
#include "stuff.h"
#include <jansson.h>
#include <curl/curl.h>
#include <inttypes.h>
#include "uint256.h"



/*
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.0 ] 000000025dea5315 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.1 ] 000000005c8e3f6e 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.2 ] 0000000149d1e28c 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.3 ] 000000004cd4589a 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.4 ] 000000013bf17144 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.5 ] 00000001008e7e47 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.6 ] 00000000b044852c 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.7 ] 000000013e1abdb1 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.8 ] 000000003d13fcc1 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.9 ] 000000001ef98066 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.10 ] 00000000347d1b00 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.11 ] 0000000129ada5ea 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.12 ] 00000001206645a4 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.13 ] 00000000744472c8 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.14 ] 00000000227867a5 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.15 ] 00000000ee01cdaa 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.16 ] 00000001f02b2fa9 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.17 ] 00000000d986614b 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.18 ] 000000012d0624ae 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.19 ] 000000008d428b5e 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.20 ] 000000020c1e1316 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.21 ] 0000000065cb251e 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.22 ] 000000028a34ec5a 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.23 ] 000000024bff9198 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.24 ] 0000000153f9b98e 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.25 ] 00000001f892ad6b 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.26 ] 0000000017a124f5 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.27 ] 0000000257c7e400 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.28 ] 00000001d9d2c44f 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.29 ] 00000001374a58b3 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.30 ] 00000001f952e9df 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.31 ] 000000003799fdd7 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.32 ] 0000000063aeeff6 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.33 ] 00000000a23740a6 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.34 ] 00000001b524d278 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.35 ] 0000000293c5aad4 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.36 ] 000000023f9576c5 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.37 ] 000000003f031211 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.38 ] 0000000191e3c7c5 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.39 ] 000000026b29f26a 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.40 ] 00000001af859ac1 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.41 ] 00000001ef19b3db 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.42 ] 000000012c943d95 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.43 ] 000000017c8da469 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.44 ] 00000000500a238c 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.45 ] 00000002400d2fdd 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.46 ] 00000001c43fc51d 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.47 ] 000000021d52569d 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.48 ] 000000022564b150 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.49 ] 00000000896efd97 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.50 ] 000000014afd647b 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.51 ] 00000002752ebc36 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.52 ] 00000000714ef3a9 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.53 ] 000000006ee7217a 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.54 ] 000000018fe616ed 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.55 ] 00000001c4e0abf4 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.56 ] 00000000d4a56261 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.57 ] 0000000014f8b968 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.58 ] 00000000f675f48f 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.59 ] 000000006ed7edd1 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.60 ] 000000018cc24823 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.61 ] 00000002354dc6c3 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.62 ] 00000002105190a4 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.63 ] 000000014dde3be3 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.64 ] 00000000f236dabe 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.65 ] 00000002635a4210 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.66 ] 000000020d1d169e 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.67 ] 000000014993912a 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.68 ] 0000000248be41d6 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.69 ] 000000009b7ab74c 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.70 ] 00000001d00ebf25 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.71 ] 00000001eeafee91 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.72 ] 00000000e0751136 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.73 ] 0000000275b0fe99 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.74 ] 000000021dbd850d 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.75 ] 000000020fd89af7 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.76 ] 000000008615699e 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.77 ] 0000000261c54635 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.78 ] 00000000d1e1cc52 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.79 ] 000000005192fad1 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.80 ] 000000014f2490bd 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.81 ] 00000001dc2efee0 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.82 ] 00000001ba28df20 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.83 ] 000000022ba139c1 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.84 ] 000000002bf1d2b7 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.85 ] 0000000176551fe0 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.86 ] 000000002046f1d9 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.87 ] 0000000254af85bd 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.88 ] 00000002583e1393 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.89 ] 000000000bf7c3e7 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.90 ] 00000000ea5981ad 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.91 ] 000000024d7f6cf7 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.92 ] 00000000f74a5b04 000000000004e2bf [-]
[ 71734.d2fd499be542c0fabf132434689cc853bce098b3b52a901c203ac8ae6960f127.93 ] 00000001a1e2b5c4 000000000004e2bf [-]
[ 71734.69bd469d1da5b86763967d8194a356b2edc88c37474baf107795ff87f4029f2e.0 ] 0000000563e6db5f 000000000004e2bf [-]

---

Predict:

[ WINNER.72245.518d2f51b83d1b0df477d04100502c334b9424c27ca8318ba77a7c78b99b831b.0 ] 000000000002373a 000000000004445f [[ Decker ] Chance to win 72197..72247 - TRUE
---
[ 72147.518d2f51b83d1b0df477d04100502c334b9424c27ca8318ba77a7c78b99b831b.0 ] 0000000001bbb490 000000000004445f [-]
[ 72147.164548fac2985dedb2748b62ea7d0ddd449d01428b7fb0d25dd1e97b512cb12e.0 ] 00000001644f17b3 000000000004445f [-]
[ 72147.4e2a0b0fdf72dbc238e06fb394bf0d092fe0a5289b4aedc52c87791ee1f13c37.2 ] 000000000b85319a 000000000004445f [-]
[ 72147.3e155a6ee26d02c1cae4dfcf6b96a295a23de563d848fdfcb19b59cf497b71a6.0 ] 000000000baa25d4 000000000004445f [-]

Found:

[ 72245.518d2f51b83d1b0df477d04100502c334b9424c27ca8318ba77a7c78b99b831b.0 ] 000000000002373a 0000000000050168 [+]
[ 72245.164548fac2985dedb2748b62ea7d0ddd449d01428b7fb0d25dd1e97b512cb12e.0 ] 000000014aa4fd00 0000000000050168 [-]
[ 72245.4e2a0b0fdf72dbc238e06fb394bf0d092fe0a5289b4aedc52c87791ee1f13c37.2 ] 0000000014c9b418 0000000000050168 [-]
[ 72245.3e155a6ee26d02c1cae4dfcf6b96a295a23de563d848fdfcb19b59cf497b71a6.0 ] 000000001216fbda 0000000000050168 [-]
---
Found block 72245
staking reward 192.00000000 VRSC!
  hash: 000000001023aeded418464235fd3f73d3d31092662a041d2e118471f66d5929
target: 0000000000050168000000000000000000000000000000000000000000000000
- timelocked until block 522508
[ Decker ] Chance to win 72297..72347 - FALSE


*/

/* Condition:

if (pastBlockIndex = komodo_chainactive(nHeight - COINBASE_MATURITY))
    {
        uint256 pastHash = pastBlockIndex->GetBlockHash();

(UintToArith256(txout.tx->GetVerusPOSHash(txout.i, nHeight, pastHash)) <= target)

    // verus hash will be the same for a given txid, output number, block height, and blockhash of 100 blocks past
    static uint256 _GetVerusPOSHash(const uint256 &txid, int32_t voutNum, int32_t height, const uint256 &pastHash, int64_t value)
    {
        CVerusHashWriter hashWriter  = CVerusHashWriter(SER_GETHASH, PROTOCOL_VERSION);

        hashWriter << ASSETCHAINS_MAGIC;
        hashWriter << pastHash;
        hashWriter << height;
        hashWriter << txid;
        hashWriter << voutNum;
        return hashWriter.GetHash();
    }

    uint256 GetVerusPOSHash(int32_t voutNum, int32_t height, const uint256 &pastHash) const
    {
        uint256 txid = GetHash();
        if (voutNum >= vout.size())
            return uint256S("ff0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f");

        return ArithToUint256(UintToArith256(_GetVerusPOSHash(txid, voutNum, height, pastHash, (uint64_t)vout[voutNum].nValue)) / vout[voutNum].nValue);
    }

    ---

72007 -> past 100 blocks -> 72107 (?)

[ WINNER.72007.4e2a0b0fdf72dbc238e06fb394bf0d092fe0a5289b4aedc52c87791ee1f13c37.0 ] 000000000003ef59 000000000005c20d [[ Decker ] Chance to win 71962..72012 - TRUE
---
[ 71912.164548fac2985dedb2748b62ea7d0ddd449d01428b7fb0d25dd1e97b512cb12e.0 ] 00000001a69d748a 000000000005c20d [-]
[ 71912.4e2a0b0fdf72dbc238e06fb394bf0d092fe0a5289b4aedc52c87791ee1f13c37.0 ] 00000000090a6502 000000000005c20d [-]
[ 71912.4e2a0b0fdf72dbc238e06fb394bf0d092fe0a5289b4aedc52c87791ee1f13c37.1 ] 0000000013ab54f1 000000000005c20d [-]
[ 71912.4e2a0b0fdf72dbc238e06fb394bf0d092fe0a5289b4aedc52c87791ee1f13c37.2 ] 000000000ba1a3ff 000000000005c20d [-]

72345

[ WINNER.72245.518d2f51b83d1b0df477d04100502c334b9424c27ca8318ba77a7c78b99b831b.0 ] 000000000002373a 000000000004445f [[ Decker ] Chance to win 72197..72247 - TRUE
---
[ 72147.518d2f51b83d1b0df477d04100502c334b9424c27ca8318ba77a7c78b99b831b.0 ] 0000000001bbb490 000000000004445f [-]
[ 72147.164548fac2985dedb2748b62ea7d0ddd449d01428b7fb0d25dd1e97b512cb12e.0 ] 00000001644f17b3 000000000004445f [-]
[ 72147.4e2a0b0fdf72dbc238e06fb394bf0d092fe0a5289b4aedc52c87791ee1f13c37.2 ] 000000000b85319a 000000000004445f [-]
[ 72147.3e155a6ee26d02c1cae4dfcf6b96a295a23de563d848fdfcb19b59cf497b71a6.0 ] 000000000baa25d4 000000000004445f [-]


*/

/* Global Variables */
#define MAXBUF 2048
#define FILENAME "VRSC.conf"
#define DELIM "="

struct config
{
    char rpcuser[MAXBUF];
    char rpcpassword[MAXBUF];
    int rpcport;
};

struct config configstruct;

/* ---------------- */


char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

struct config get_config(char *filename)
{
        struct config configstruct;
        memset(&configstruct, 0, sizeof(configstruct)); // (???) check release build

        FILE *file = fopen (filename, "r");

        if (file != NULL)
        {
                char line[MAXBUF];
                int i = 0;

                while(fgets(line, sizeof(line), file) != NULL)
                {
                        char *cfline, *key;
                        cfline = strstr((char *)line,DELIM);
                        if (cfline) {
                            *cfline = 0;
                            key = trimwhitespace(line);
                            //printf("[1] key = %s\n",key);
                            cfline = cfline + strlen(DELIM);
                            cfline = trimwhitespace(cfline);
                            //printf("[2] value = %s\n",cfline);
                            if (strcmp(key,"rpcuser") == 0)
                                memcpy(configstruct.rpcuser,cfline,strlen(cfline));
                            if (strcmp(key,"rpcpassword") == 0)
                                memcpy(configstruct.rpcpassword,cfline,strlen(cfline));
                            if (strcmp(key,"rpcport") == 0)
                                configstruct.rpcport = atoi(cfline);
                        }
                        i++;
                }
                fclose(file);
        }
        return configstruct;

}

/* verus_hash.cpp -> CVerusHash::Hash(void *result, const void *data, size_t len) */
void VerusHash(void *result, const void *data, size_t len)
{
    unsigned char buf[128];
    unsigned char *bufPtr = buf;
    int pos = 0, nextOffset = 64;
    unsigned char *bufPtr2 = bufPtr + nextOffset;
    unsigned char *ptr = (unsigned char *)data;
    uint32_t count = 0;

    // put our last result or zero at beginning of buffer each time
    memset(bufPtr, 0, 32);

    // digest up to 32 bytes at a time
    for ( ; pos < len; pos += 32)
    {
        if (len - pos >= 32)
        {
            memcpy(bufPtr + 32, ptr + pos, 32);
        }
        else
        {
            int i = (int)(len - pos);
            memcpy(bufPtr + 32, ptr + pos, i);
            memset(bufPtr + 32 + i, 0, 32 - i);
        }

        count++;

        //printf("[%02d.1] ", count); for (int z=0; z<64; z++) printf("%02x", bufPtr[z]); printf("\n");
        haraka512_zero(bufPtr2, bufPtr); // ( out, in)
        bufPtr2 = bufPtr;
        bufPtr += nextOffset;
        //printf("[%02d.2] ", count); for (int z=0; z<64; z++) printf("%02x", bufPtr[z]); printf("\n");


        nextOffset *= -1;
    }
    memcpy(result, bufPtr, 32);
};

void dump(unsigned char buffer[],int len) {
int i,j;
unsigned char ch;

printf("\n");
for (i=0;i<len;i+=16) {
  printf("%04x: ",i);
  for (j=0;j<16;j++){
   if ((i+j) < len) printf("%02x ",buffer[i+j]&0xff);
   else printf("   ");}
  printf(" *");
  for (j=0;j<16;j++) {
   if ((i+j) < len) {
    ch=buffer[i+j];
    if ((ch < 0x20)||((ch > 0x7e)&&(ch<0xc0))) putchar('.');
    else putchar(ch);
   }
   else printf(" ");
  }
  printf("*\n");
 }
}

// *** iguana_utils.c ***

char hexbyte(int32_t c)
{
    c &= 0xf;
    if ( c < 10 )
        return('0'+c);
    else if ( c < 16 )
        return('a'+c-10);
    else return(0);
}

int32_t _unhex(char c)
{
    if ( c >= '0' && c <= '9' )
        return(c - '0');
    else if ( c >= 'a' && c <= 'f' )
        return(c - 'a' + 10);
    else if ( c >= 'A' && c <= 'F' )
        return(c - 'A' + 10);
    return(-1);
}

int32_t is_hexstr(char *str,int32_t n)
{
    int32_t i;
    if ( str == 0 || str[0] == 0 )
        return(0);
    for (i=0; str[i]!=0; i++)
    {
        if ( n > 0 && i >= n )
            break;
        if ( _unhex(str[i]) < 0 )
            break;
    }
    if ( n == 0 )
        return(i);
    return(i == n);
}

int32_t unhex(char c)
{
    int32_t hex;
    if ( (hex= _unhex(c)) < 0 )
    {
        //printf("unhex: illegal hexchar.(%c)\n",c);
    }
    return(hex);
}

unsigned char _decode_hex(char *hex) { return((unhex(hex[0])<<4) | unhex(hex[1])); }

int32_t decode_hex(unsigned char *bytes,int32_t n,char *hex)
{
    int32_t adjust,i = 0;
    //printf("decode.(%s)\n",hex);
    if ( is_hexstr(hex,n) <= 0 )
    {
        memset(bytes,0,n);
        return(n);
    }
    if ( hex[n-1] == '\n' || hex[n-1] == '\r' )
        hex[--n] = 0;
    if ( hex[n-1] == '\n' || hex[n-1] == '\r' )
        hex[--n] = 0;
    if ( n == 0 || (hex[n*2+1] == 0 && hex[n*2] != 0) )
    {
        if ( n > 0 )
        {
            bytes[0] = unhex(hex[0]);
            printf("decode_hex n.%d hex[0] (%c) -> %d hex.(%s) [n*2+1: %d] [n*2: %d %c] len.%ld\n",n,hex[0],bytes[0],hex,hex[n*2+1],hex[n*2],hex[n*2],(long)strlen(hex));
        }
        bytes++;
        hex++;
        adjust = 1;
    } else adjust = 0;
    if ( n > 0 )
    {
        for (i=0; i<n; i++)
            bytes[i] = _decode_hex(&hex[i*2]);
    }
    //bytes[i] = 0;
    return(n + adjust);
}

int32_t init_hexbytes_noT(char *hexbytes,unsigned char *message,long len)
{
    int32_t i;
    if ( len <= 0 )
    {
        hexbytes[0] = 0;
        return(1);
    }
    for (i=0; i<len; i++)
    {
        hexbytes[i*2] = hexbyte((message[i]>>4) & 0xf);
        hexbytes[i*2 + 1] = hexbyte(message[i] & 0xf);
        //printf("i.%d (%02x) [%c%c]\n",i,message[i],hexbytes[i*2],hexbytes[i*2+1]);
    }
    hexbytes[len*2] = 0;
    //printf("len.%ld\n",len*2+1);
    return((int32_t)len*2+1);
}

void reverse_hexstr(char *str)
{
    int i,n;
    char *rev;
    n = (int32_t)strlen(str);
    rev = (char *)malloc(n + 1);
    for (i=0; i<n; i+=2)
    {
        rev[n-2-i] = str[i];
        rev[n-1-i] = str[i+1];
    }
    rev[n] = 0;
    strcpy(str,rev);
    free(rev);
}

// *** iguana_utils.c ***

void getblockhash(uint32_t nHeight, unsigned char *hash) {

    unsigned char tmp[32];
    unsigned char tmp_str[65];

    unsigned char *getblockhash_format = "{\"jsonrpc\": \"1.0\", \"id\":\"curltest\", \"method\": \"getblockhash\", \"params\": [%d] }";

    uint32_t getblockhash_req_size = strlen(getblockhash_format) + 10 + 1; // 10 - strlen("4294967295")
    unsigned char *getblockhash_req = malloc(getblockhash_req_size);
    memset(getblockhash_req, 0, getblockhash_req_size);
    snprintf(getblockhash_req, getblockhash_req_size, getblockhash_format, nHeight);

    memset(hash, 0, 32);
    char *txt = daemon_request("127.0.0.1", configstruct.rpcport, configstruct.rpcuser, configstruct.rpcpassword, getblockhash_req);
    if (txt) {
            json_t *j_root;
            json_error_t error;
            json_t *j_result;
            j_root = json_loads(txt, 0, &error);
            free(txt);
            j_result = json_object_get(j_root, "result");
            if(json_is_string(j_result)) {
                //printf(GREEN "%s\n" RESET,json_string_value(j_result));
                memcpy(tmp_str, json_string_value(j_result), sizeof(tmp_str));
                reverse_hexstr(tmp_str);
                decode_hex(hash, 64, tmp_str);
            }
            json_decref(j_root);
    }
    free(getblockhash_req);
}

uint64_t getvoutvalue(unsigned char *txid_str, uint32_t voutNum) {

    unsigned char tmp[32];
    unsigned char tmp_str[65];
    uint64_t valueSat = 0;
    uint32_t i;

    unsigned char *getrawtransaction_format = "{\"jsonrpc\": \"1.0\", \"id\":\"curltest\", \"method\": \"getrawtransaction\", \"params\": [\"%s\", 1] }";

    uint32_t getrawtransaction_req_size = strlen(getrawtransaction_format) + strlen(txid_str) + 1;
    unsigned char *getrawtransaction_req = malloc(getrawtransaction_req_size);
    memset(getrawtransaction_req, 0, getrawtransaction_req_size);
    snprintf(getrawtransaction_req, getrawtransaction_req_size, getrawtransaction_format, txid_str);

    char *txt = daemon_request("127.0.0.1", configstruct.rpcport, configstruct.rpcuser, configstruct.rpcpassword, getrawtransaction_req);
    if (txt) {
        json_t *j_root;
        json_error_t error;
        json_t *j_result, *j_vout, *j_data, *j_valueSat;
        j_root = json_loads(txt, 0, &error);
        //printf("%s\n",txt);
        free(txt);

        if json_is_object(j_root) {
           j_result = json_object_get(j_root, "result");
           if json_is_object(j_result) {
                j_vout = json_object_get(j_result, "vout");
                    if (json_is_array(j_vout)) {
                        //for(i = 0; i < json_array_size(j_vout); i++)
                            {
                                i = voutNum;
                                j_data = json_array_get(j_vout, i);
                                if(json_is_object(j_data)) {
                                    j_valueSat = json_object_get(j_data, "valueSat");
                                    if json_is_integer(j_valueSat) {
                                        valueSat = json_integer_value(j_valueSat);
                                        //printf("%" PRId64 "\n", valueSat);
                                    }
                                }
                            }
                    }
           }
        }

        json_decref(j_root);
    }
    free(getrawtransaction_req);
    return valueSat;

}

int main(int argc, char* argv[])
{

    /* Init */
    gcurl_init();

    char userhome[MAXBUF];
	#ifndef _WIN32
		snprintf(userhome, MAXBUF, "%s/.komodo/VRSC/VRSC.conf", getenv("HOME"));
	#else
		snprintf(userhome, MAXBUF, "%s\\Komodo\\VRSC\\VRSC.conf", getenv("APPDATA"));
	#endif // !_WIN32

    configstruct = get_config(userhome);

    unsigned char checkdata[] = { 0xc2, 0xa4, 0x00, 0x00, 0xad, 0x8a, 0x58, 0xe2 };
    unsigned char buf[128];
    int i, j;

    //[Decker] CVerusHash::Hash data = c2a40000ad8a58e2
    //[Decker] CVerusHash::Hash result = b10536cc23e50a2165e7c1dd5ae9a0f072dc963bce52dec2c74173d7f628a837
    memset(buf, 0, sizeof(buf));
    VerusHash(buf, checkdata, sizeof(checkdata));
    for (i=0; i < 32; i++) { printf("%02x", buf[i]); } printf("\n");
    printf("b10536cc23e50a2165e7c1dd5ae9a0f072dc963bce52dec2c74173d7f628a837\n");

    /*/* Condition:

if (pastBlockIndex = komodo_chainactive(nHeight - COINBASE_MATURITY))
    {
        uint256 pastHash = pastBlockIndex->GetBlockHash();

(UintToArith256(txout.tx->GetVerusPOSHash(txout.i, nHeight, pastHash)) <= target)

    // verus hash will be the same for a given txid, output number, block height, and blockhash of 100 blocks past
    static uint256 _GetVerusPOSHash(const uint256 &txid, int32_t voutNum, int32_t height, const uint256 &pastHash, int64_t value)
    {
        CVerusHashWriter hashWriter  = CVerusHashWriter(SER_GETHASH, PROTOCOL_VERSION);

        hashWriter << ASSETCHAINS_MAGIC;
        hashWriter << pastHash;
        hashWriter << height;
        hashWriter << txid;
        hashWriter << voutNum;
        return hashWriter.GetHash();
    }

    uint256 GetVerusPOSHash(int32_t voutNum, int32_t height, const uint256 &pastHash) const
    {
        uint256 txid = GetHash();
        if (voutNum >= vout.size())
            return uint256S("ff0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f0f");

        return ArithToUint256(UintToArith256(_GetVerusPOSHash(txid, voutNum, height, pastHash, (uint64_t)vout[voutNum].nValue)) / vout[voutNum].nValue);
    }

    ---
*/

    /* [ WINNER.72820.b9b4deb9d6e485009353608a597325d727c876a705f8994786776fcc203f7abe.0 ] 0000000000033723 000000000004d831

    "value": 1507.97299492,
    "valueZat": 150797299492,
    "valueSat": 150797299492,
    */

    uint64_t valueSat = 150797299492;
    uint32_t ASSETCHAINS_MAGIC = 0xe2588aad;
    uint32_t COINBASE_MATURITY = 100;

    uint32_t nHeight, pastBlockIndex;
    unsigned char txid[32], tmp[32], pastHash[32];
    unsigned char tmp_str[65];

    unsigned char verusin[4 + 32 + 4 + 32 + 4]; // ASSETCHAINS_MAGIC, pastHash, height, txid, voutNum
    unsigned char *ptr;
    unsigned char verushash[32];

    unsigned char txid_str[] = "b9b4deb9d6e485009353608a597325d727c876a705f8994786776fcc203f7abe";
    uint32_t voutNum = 0;

    printf("%" PRIu64 "\n", valueSat);

    printf("COINBASE_MATURITY.%d ASSETCHAINS_MAGIC.%d\n", COINBASE_MATURITY, ASSETCHAINS_MAGIC);
    printf("txid.%s\n", txid_str);

    memcpy(tmp_str, txid_str, sizeof(tmp_str)); reverse_hexstr(tmp_str); decode_hex(txid, 64, tmp_str); // transform hex txid_str to bytes buffer (txid)
    dump(txid, 32);

    nHeight = 72820;
    pastBlockIndex = nHeight - COINBASE_MATURITY;
    /* pastHash -> pastBlockIndex->GetBlockHash() =
       72820: 0000000000020e3176bc654f37ae46ced9a7a56c50e136afa4fd63fbf090d6c6
       72720: d37da99d42eb88514d4b01cf4065b2e66856f8901e7de2593e575fe5a5437d67
    */
    getblockhash(pastBlockIndex, pastHash);

    init_hexbytes_noT(tmp_str, pastHash, 32); reverse_hexstr(tmp_str);
    printf("pasthash = %s\n", tmp_str);

    valueSat = getvoutvalue(txid_str, voutNum);
    printf("%" PRIu64 "\n", valueSat);

    /*
    hashWriter << ASSETCHAINS_MAGIC;  4
        hashWriter << pastHash;      32
        hashWriter << height;         4
        hashWriter << txid;          32
        hashWriter << voutNum;        4
         */

    memset(verusin, 0, sizeof(verusin));
    ptr = verusin;
    memcpy(ptr,&ASSETCHAINS_MAGIC, sizeof(ASSETCHAINS_MAGIC)); ptr +=sizeof(ASSETCHAINS_MAGIC);
    memcpy(ptr,pastHash, sizeof(pastHash)); ptr +=sizeof(pastHash);
    memcpy(ptr,&nHeight, sizeof(nHeight)); ptr +=sizeof(nHeight);
    memcpy(ptr,txid, sizeof(txid)); ptr +=sizeof(txid);
    memcpy(ptr,&voutNum, sizeof(voutNum)); ptr +=sizeof(voutNum);

    dump(verusin, sizeof(verusin));

    memset(verushash, 0, sizeof(verushash));
    VerusHash(verushash, verusin, sizeof(verusin));
    dump(verushash, sizeof(verushash));

    init_hexbytes_noT(tmp_str, verushash, 32); reverse_hexstr(tmp_str);
    printf("veruhash = 0x%s\n", tmp_str);

    // 0x0070e4a796d184669b4190c2f69b5c8940f5fb32f4b3a4b1dccde2a7f66c0277 / 150797299492 = 0x 3 3723 f8b0 cfdd 69f2 e252 91cc 013d 68a9 6e7d ce45 8d03 9fc4 8345



    gcurl_cleanup();

    return 0;
}
