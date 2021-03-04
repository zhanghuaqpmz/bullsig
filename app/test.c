/*Copyright (C)[2019-2029] [Bruce Zhang, bjbrucezhang@sina.com]
* 
* All rights reserved
* 
*/
/* Change Logs:
*     Date               Author           Notes
*     2019-04-10         bruce.zhang        the first version
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "ecdsa_func.h"
#include "common_func.h"



void usage(void)
{
    printf(
            "\n          Decentralized Distributed Co-Signing Software BULLSIG Version %d（Command List）\r\n"
           "set signing-committee's size(default is 3)             : setsize x(signing-committee's size)\r\n"
           "generate address and private key                       : genkey\r\n"
           "generate fragments of a private key                    : genfrag xxx(the key file will be split)\r\n"
           "generate signature using whole private key             : sig xxx(key file)  yyy(message will be signed)\r\n"     
           "generate signature using private-key's fragments       : bullsig xxx(message will be signed)\r\n" 
           "verify a signature                                     : verify xxx(the signature file will be verified) yyy(the message be signed)\r\n"                 
           "exit this software                                     : quit\r\n"
           "help information                                       : help\r\n\n", SW_VER);
}

char user_input_command[INPUT_MAX_LEN] = {0, };

int main(int argc, char* argv[])
{
    usage();
    test_init_temp_k_c();
    test_init_temp_fragment_signature_file_name();
    while(1)
    {
        memset(user_input_command, 0, INPUT_MAX_LEN);
        scanf("%s", user_input_command);
    
        if((!strncmp(user_input_command, "help", strlen("help")))&&(strlen(user_input_command) == strlen("help")))
        {
            usage();
        }
        else if((!strncmp(user_input_command, "genkey", strlen("genkey")))&&(strlen(user_input_command) == strlen("genkey")))
        {
            secp256k1_generate_key();
        }
        else if((!strncmp(user_input_command, "genfrag", strlen("genfrag")))&&(strlen(user_input_command) == strlen("genfrag")))
        {
            char file_name[INPUT_MAX_LEN] = {0, };
            scanf("%s", file_name);
            secp256k1_generate_fragments(file_name);
        }
        else if((!strncmp(user_input_command, "setsize", strlen("setsize")))&&(strlen(user_input_command) == strlen("setsize")))
        {
            int part_count = 0;
            scanf("%d", &part_count);
            if((part_count<2)||(part_count>100))
            {
                printf(L_RED "Input out of range, the signing-committee size is at least 2 and at most 100\r\n");
                printf(NONE "\r\n\r\n");  
                continue;             
            }
            if(part_count != FRAGMENT_COUNT)
            {
                int temp = FRAGMENT_COUNT;
                test_free_temp_k_c();
                test_free_temp_fragment_signature_file_name();
                FRAGMENT_COUNT = part_count;
                test_init_temp_k_c();
                test_init_temp_fragment_signature_file_name();  
                printf(GREEN "Successfully adjust signing-committee size from %d to %d\r\n", temp, part_count);
                printf(NONE "\r\n");
            }
            else
            {
                 printf(RED "The size of the newly set is consistent with the original one\r\n");   
                 printf(NONE "\r\n");            
            }
        }
        else if((!strncmp(user_input_command, "sig", strlen("sig")))&&(strlen(user_input_command) == strlen("sig")))
        {
            char privkey_file_name[INPUT_MAX_LEN] = {0, };
            scanf("%s", privkey_file_name);
            char msg[INPUT_MAX_LEN] = {0, };
            scanf("%s", msg);
            char r[100] = {0, };
            char s[100] = {0, };            
            test_secp256k1_privkey_sign(privkey_file_name, msg, strlen(msg), r, s);

            memset(privkey_file_name, 0, INPUT_MAX_LEN);
            memset(msg, 0, INPUT_MAX_LEN);
            memset(r, 0, 100);
            memset(s, 0, 100);

        }
        else if((!strncmp(user_input_command, "bullsig", strlen("bullsig")))&&(strlen(user_input_command) == strlen("bullsig")))
        {
            char msg[INPUT_MAX_LEN] = {0, };

            scanf("%s", msg);
            test_secp256k1_co_sign(msg, strlen(msg));

            memset(msg, 0, INPUT_MAX_LEN);

        }
        else if((!strncmp(user_input_command, "verify", strlen("verify")))&&(strlen(user_input_command) == strlen("verify")))
        {
            char msg[INPUT_MAX_LEN] = {0, };

            int result = 0;

            char signature_file_name[INPUT_MAX_LEN] = {0, };
            scanf("%s", signature_file_name);

            scanf("%s", msg);
            test_secp256k1_verify_sigfile(msg, strlen(msg), signature_file_name, &result);

            memset(signature_file_name, 0, INPUT_MAX_LEN);
            memset(msg, 0, INPUT_MAX_LEN);

        }
        else if((!strncmp(user_input_command, "quit", strlen("quit")))&&(strlen(user_input_command) == strlen("quit")))
        {
            break;
        }              
        else
        {
            printf(L_RED "Input error!\r\nPlease use \'help\' command to get helping information\r\n");
            printf(NONE "\r\n\r\n");
        }
    }
    test_free_temp_k_c();
    test_free_temp_fragment_signature_file_name();

    return 1;
}
