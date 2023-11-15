/* conf.c (GENERATED FILE; DO NOT EDIT) */

#include <conf.h>
#include <device.h>

#include <loopback.h>
#include <null.h>
#include <uart.h>
#include <tty.h>

extern devcall ioerr(void);
extern devcall ionull(void);

/* device independent I/O switch */

const device devtab[NDEVS] =
{
/**
 * Format of entries is:
 * dev-number, minor-number, dev-name,
 * init, open, close,
 * read, write, seek,
 * getc, putc, control,
 * dev-csr-address, intr-handler, irq
 */

/* SERIAL0 is uart */
	{ 0, 0, "SERIAL0",
	  (void *)uartInit, (void *)ionull, (void *)ionull,
	  (void *)uartRead, (void *)uartWrite, (void *)ioerr,
	  (void *)uartGetc, (void *)uartPutc, (void *)uartControl,
	  (void *)0xb40003f8, (void *)uartInterrupt, 12 },

/* DEVNULL is null */
	{ 1, 0, "DEVNULL",
	  (void *)ionull, (void *)ionull, (void *)ionull,
	  (void *)ionull, (void *)ionull, (void *)ioerr,
	  (void *)ionull, (void *)ionull, (void *)ioerr,
	  (void *)0x0, (void *)ioerr, 0 },

/* LOOP0 is loopback */
	{ 2, 0, "LOOP0",
	  (void *)loopbackInit, (void *)loopbackOpen, (void *)loopbackClose,
	  (void *)loopbackRead, (void *)loopbackWrite, (void *)ioerr,
	  (void *)loopbackGetc, (void *)loopbackPutc, (void *)loopbackControl,
	  (void *)0x0, (void *)ioerr, 0 },

/* TTYLOOP is tty */
	{ 3, 0, "TTYLOOP",
	  (void *)ttyInit, (void *)ttyOpen, (void *)ttyClose,
	  (void *)ttyRead, (void *)ttyWrite, (void *)ioerr,
	  (void *)ttyGetc, (void *)ttyPutc, (void *)ttyControl,
	  (void *)0x0, (void *)ioerr, 0 },

/* CONSOLE is tty */
	{ 4, 1, "CONSOLE",
	  (void *)ttyInit, (void *)ttyOpen, (void *)ttyClose,
	  (void *)ttyRead, (void *)ttyWrite, (void *)ioerr,
	  (void *)ttyGetc, (void *)ttyPutc, (void *)ttyControl,
	  (void *)0x0, (void *)ioerr, 0 }
};
