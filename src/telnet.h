#ifndef __TELNET_H__
#define __TELNET_H__

#include <stddef.h>

// Telnet commands as defined in RFC854
typedef enum {
	SE   = 240,
	NOP  = 241,
	DM   = 242,
	BRK  = 243,
	IP   = 244,
	AYT  = 246,
	EC   = 247,
	EL   = 248,
	GA   = 249,
	SB   = 250,
	WILL = 251,
	WONT = 252,
	DO   = 253,
	DONT = 254,
	IAC  = 255
} telnet_command;

//Telnet options as defined in RFC1060
typedef enum {
	Binary        =  0,
	Echo          =  1,
	Reconnection  =  2,
	SupprGoAhead  =  3,
	ApproxMSN     =  4,
	Status        =  5,
	TimingMark    =  6,
	RCTransEcho   =  7,
	OutLineWidth  =  8,
	OutPageSize   =  9,
	OutCRDisp     = 10,
	OutHTStops    = 11,
	OutHTDisp     = 12,
	OutFFDisp     = 13,
	OutVTStops    = 14,
	OutVTDisp     = 15,
	OutLFDisp     = 16,
	ExtASCII      = 17,
	Logout        = 18,
	ByteMacro     = 19,
	DataEntryTerm = 20,
	SUPDUP        = 21,
	SUPDUPOut     = 22,
	SendLocation  = 23,
	TermType      = 24,
	EndOfRecord   = 25,
	TACACSUserId  = 26,
	OutputMarking = 27,
	TermLocNum    = 28,
	Tln3270Regime = 29
} telnet_option;

typedef struct {
	int socket;
} telnet_connection;

// create a telnet connection from a connected tcp socket
telnet_connection* telnet_init(int socket);

// send text through the telnet connection, does all the necessary NVT
// conversions according to the options currently in use
void telnet_send_text(telnet_connection *conn, char* buf, size_t len);

// sends raw bytes through the telnet connection
void telnet_send(telnet_connection *conn, char* buf, size_t len);

// negotiate a telnet option
// state should be one of DO, DONT, WILL or WONT
void telnet_negotiate(telnet_connection* conn, telnet_option opt, telnet_command state);

// recive raw bytes through the telnet connection
// returns the number of bytes actually read
int telnet_recv(telnet_connection* conn, char* buf, size_t maxlen);

// recive text through the telnet_connection
// returns the number of bytes put in the output buffer after conversions
int telnet_recv_text(telnet_connection* conn, char* buf, size_t maxlen);

// cleans up the telnet connection, the pointer should not be used afterward
// doesn't close the socket
void telnet_close(telnet_connection* conn)

#endif //__TELNET_H__
