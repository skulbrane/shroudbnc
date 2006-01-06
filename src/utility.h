/*******************************************************************************
 * shroudBNC - an object-oriented framework for IRC                            *
 * Copyright (C) 2005 Gunnar Beutner                                           *
 *                                                                             *
 * This program is free software; you can redistribute it and/or               *
 * modify it under the terms of the GNU General Public License                 *
 * as published by the Free Software Foundation; either version 2              *
 * of the License, or (at your option) any later version.                      *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License           *
 * along with this program; if not, write to the Free Software                 *
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. *
 *******************************************************************************/

char* LastArg(char* Args);

class CIRCConnection;
class CBouncerUser;

typedef struct command_s {
	char *Category;
	char *Description;
	char *HelpText;
} command_t;

typedef class CHashtable<command_t *, false, 16> *commandlist_t;

typedef struct utility_s {
	const char *(*ArgParseServerLine)(const char *Data);
	const char *(*ArgTokenize)(const char *Data);
	const char **(*ArgToArray)(const char *Args);
	void (*ArgRejoinArray)(const char **ArgV, int Index);
	const char **(*ArgDupArray)(const char **ArgV);
	void (*ArgFree)(const char *Args);
	void (*ArgFreeArray)(const char **Array);
	const char *(*ArgGet)(const char *Args, int Arg);
	int (*ArgCount)(const char *Args);

	void (*FlushCommands)(commandlist_t *Commands);
	void (*AddCommand)(commandlist_t *Commands, const char *Name, const char *Category, const char *Description, const char *HelpText);
	void (*DeleteCommand)(commandlist_t *Commands, const char *Name);
	int (*CmpCommandT)(const void *pA, const void *pB);
} utility_t;

const char *ArgParseServerLine(const char *Data);
const char *ArgTokenize(const char *Data);
const char **ArgToArray(const char *Args);
void ArgRejoinArray(const char **ArgV, int Index);
const char **ArgDupArray(const char **ArgV);
void ArgFree(const char *Args);
void ArgFreeArray(const char **Array);
const char *ArgGet(const char *Args, int Arg);
int ArgCount(const char *Args);

SOCKET SocketAndConnect(const char *Host, unsigned short Port, const char *BindIp = NULL);
SOCKET SocketAndConnectResolved(in_addr Host, unsigned short Port, in_addr *BindIp);

CIRCConnection *CreateIRCConnection(const char *Host, unsigned short Port, CBouncerUser *Owning, const char *BindIp = NULL, bool SSL = false);
SOCKET CreateListener(unsigned short Port, const char *BindIp = NULL);

char* NickFromHostmask(const char *Hostmask);
void string_free(char *string);

const char *UtilMd5(const char *String);

void FlushCommands(commandlist_t *Commands);
void AddCommand(commandlist_t *Commands, const char *Name, const char *Category, const char *Description, const char *HelpText);
void DeleteCommand(commandlist_t *Commands, const char *Name);
int CmpCommandT(const void *pA, const void *pB);
void DestroyCommandT(command_t *Command);

#define BNCVERSION "1.1 $Revision: 371 $"
#define INTERFACEVERSION 20

extern const char *g_ErrorFile;
extern unsigned int g_ErrorLine;

#define LOGERROR g_Bouncer->InternalSetFileAndLine(__FILE__, __LINE__); g_Bouncer->InternalLogError

#ifndef min
#define min(a, b) ((a)<(b) ? (a) : (b))
#endif