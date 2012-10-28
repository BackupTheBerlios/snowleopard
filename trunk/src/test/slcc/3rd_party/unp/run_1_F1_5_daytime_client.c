/*==============================================================================
  Snow Leopard C++ Compiler Front End 
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version
  
  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
  details.
  
  You should have received a copy of the GNU General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>
  ============================================================================*/

//------------------------------------------------------------------------------
// run_1_F1_5_daytime_client.c
//------------------------------------------------------------------------------
// Figure 1.5 from Advanced Programming in the UNIX Environment.  
//------------------------------------------------------------------------------

//##############################################################################
// SLTST - Config
//
// [build]  = [strict]
// [source] = run_1_F1_5_daytime_client.c;unp_error_functions.c
// [run]    = [arg <ip_address:string>]
// [result] = [run <ip_address:valid>]
//              [no_assert][stdout:same_as("<TODO>")];
//            [run <directory:invalid>]
//              [no_assert][stdout("<TODO>")];
//            [run]
//              [no_assert]
//              [stdout("usage: <program> <ip address>")]
//##############################################################################

#include "unp_header.h"

//------------------------------------------------------------------------------
// main function
//
int main (int argc, char** argv)
{
  int sockfd, n;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  if (argc != 2)
    err_quit ("usage: a.out <ip address>");

  if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0)
    err_sys ("socket error");

  bzero (&servaddr, sizeof (servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(13); /* Daytime server */

  if (inet_pton (AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    err_quit ("inet_pton error for %s", argv[1]);

  if (connect (sockfd, (SA*) &servaddr, sizeof (servaddr)) < 0)
    err_sys ("connect error");

  while ((n = read (sockfd, recvline, MAXLINE)) > 0)
    {
      recvline[n] = 0; /* NULL terminate */
      if (fputs (recvline, stdout) == EOF)
	err_sys ("fputs error");
    }

  if (n < 0)
    err_sys ("read error");

  exit (0);
}
//------------------------------------------------------------------------------

//-<EOF>
