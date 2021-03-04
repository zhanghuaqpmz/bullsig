/*Copyright (C)[2019-2029] [Bruce Zhang, bjbrucezhang@sina.com]
* 
* All rights reserved
* 
*/
/* Change Logs:
*     Date               Author           Notes
*     2019-04-10         bruce.zhang        the first version
*/


#ifndef _ECDSA_FUNC_H_
#define _ECDSA_FUNC_H_


#ifdef __cplusplus
extern "C"{
#endif


#define SW_VER (1)
#define INPUT_MAX_LEN (10000)

#define PRIVKEY_ENCRYPT_KEY_LEN (32)

#define AES_KEYSIZE (128)

#if (AES_KEYSIZE == 128)
#define AES_ALGORITHM_PARAM   "aes-128-ctr"
#elif(AES_KEYSIZE == 192)
#define AES_ALGORITHM_PARAM   "aes-192-ctr"
#elif(AES_KEYSIZE == 256)
#define AES_ALGORITHM_PARAM   "aes-256-ctr"
#else
#error AES_AES_KEYSIZE set error!!!
#endif


extern int FRAGMENT_COUNT;

typedef struct _ecdsa_keystore_st {
    char c_privkey[65];
    char c_privkey_ciphertext[65];	
    char c_pubkey_x[65];
	char c_address[41];
	int pc;
	int dklen;
	int n;
	int p;
	int r;
	char uuid[100];
	char c_salt[65];
	char c_iv[33];	
	char c_mac[65];
}ecdsa_keystore_st;


typedef struct _ecdsa_fragment_st {
    char c_fragment_ciphertext[65];	
    char c_pubkey_x[65];
	char c_address[41];
	char c_salt[65];
	char c_iv[33];	
	char c_mac[65];
	int pc;
	int dklen;
	int n;
	int p;
	int r;
	char uuid[100];
	int count;   
	int serial;   //begin from 0
}ecdsa_fragment_st;

typedef struct _ecdsa_fragment_signature_st {
    char c_res[65];
	char uuid[100];
	int count;   
	int serial;   //begin from 0
}ecdsa_fragment_signature_st;


typedef struct _test_ecdsa_signature_st {
    char c_r[65];
    char c_s[65];
    char c_pubkey_x[65];
	int pc;
	char uuid[100];
}test_ecdsa_signature_st;

int get_sw_ver(void);
int test_init_temp_k_c(void);
int test_init_temp_fragment_signature_file_name(void);
int test_free_temp_k_c(void);
int test_free_temp_fragment_signature_file_name(void);

int secp256k1_generate_key(void);
int secp256k1_generate_fragments(char* address_file);
int test_secp256k1_privkey_sign(char* privkey_file, char* msg, int msg_len, char* r, char* s);
int secp256k1_fragment_sign(char* fragment_file, char* message, char* res, int order);
int test_secp256k1_co_sign(char* message, int msg_len);
int test_secp256k1_verify_sigfile(char* msg, int msg_len, char* sigfile, int* result);


#ifdef __cplusplus
}
#endif


#endif   //#ifndef  _ECDSA_FUNC_H_