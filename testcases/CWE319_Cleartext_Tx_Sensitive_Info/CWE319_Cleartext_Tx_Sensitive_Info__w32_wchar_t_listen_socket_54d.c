/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54d.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: listen_socket Read the password using a listen socket (server side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#pragma comment(lib, "advapi32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */


/* bad function declaration */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e_badSink(wchar_t * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54d_badSink(wchar_t * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e_badSink(password);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e_goodG2BSink(wchar_t * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54d_goodG2BSink(wchar_t * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e_goodG2BSink(password);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e_goodB2GSink(wchar_t * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54d_goodB2GSink(wchar_t * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_54e_goodB2GSink(password);
}

