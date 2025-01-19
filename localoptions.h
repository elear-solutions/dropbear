#ifndef DROPBEAR_LOCAL_OPTIONS_H
#define DROPBEAR_LOCAL_OPTIONS_H
/*
                     > > > Read This < < <

default_options.h documents compile-time options, and provides default values.

Local customisation should be added to localoptions.h which is
used if it exists in the build directory. Options defined there will override
any options in this file.

IMPORTANT: Some options will require "make clean" after changes */

/* Default hostkey paths - these can be specified on the command line.
 * Homedir is prepended if path begins with ~/
 */
#define DSS_PRIV_FILENAME "/home/etc/dropbear/dropbear_dss_host_key"
#define RSA_PRIV_FILENAME "/home/etc/dropbear/dropbear_rsa_host_key"
#define ECDSA_PRIV_FILENAME "/home/etc/dropbear/dropbear_ecdsa_host_key"
#define ED25519_PRIV_FILENAME "/home/etc/dropbear/dropbear_ed25519_host_key"


/* Disable public key authentication */
#define DROPBEAR_SVR_PUBKEY_AUTH 0

/* Enable password authentication */
#define DROPBEAR_SVR_PASSWORD_AUTH 1

/* Disable other unused features for a minimal setup */

/* Note: Both DROPBEAR_CLI_PROXYCMD and DROPBEAR_CLI_NETCAT must be set to
 * allow multihop dbclient connections */

/* Allow using -J <proxycommand> to run the connection through a
   pipe to a program, rather the normal TCP connection */
#define DROPBEAR_CLI_PROXYCMD 0

/* Enable "Netcat mode" option. This will forward standard input/output
 * to a remote TCP-forwarded connection */
#define DROPBEAR_CLI_NETCAT 0

/* Enable Authentication Agent Forwarding */
#define DROPBEAR_SVR_AGENTFWD 0
#define DROPBEAR_CLI_AGENTFWD 0

/* Enable TCP Fowarding */
/* 'Local' is "-L" style (client listening port forwarded via server)
 * 'Remote' is "-R" style (server listening port forwarded via client) */
#define DROPBEAR_CLI_LOCALTCPFWD 0
#define DROPBEAR_CLI_REMOTETCPFWD 0

#define DROPBEAR_SVR_LOCALTCPFWD 0
#define DROPBEAR_SVR_REMOTETCPFWD 0
#define DROPBEAR_SVR_LOCALSTREAMFWD 0

/* Enable Chacha20-Poly1305 authenticated encryption mode. This is
 * generally faster than AES256 on CPU w/o dedicated AES instructions,
 * having the same key size. Recommended.
 * Compiling in will add ~5,5kB to binary size on x86-64 */
#define DROPBEAR_CHACHA20POLY1305 1

/* Hostkey/public key algorithms - at least one required, these are used
 * for hostkey as well as for verifying signatures with pubkey auth.
 * RSA is recommended.
 *
 * See: RSA_PRIV_FILENAME and DSS_PRIV_FILENAME */
#define DROPBEAR_RSA 1
/* Newer SSH implementations use SHA256 for RSA signatures. SHA1
 * support is required to communicate with some older implementations.
 * It will be removed in future due to SHA1 insecurity, it can be
 * disabled with DROPBEAR_RSA_SHA1 set to 0 */
#define DROPBEAR_RSA_SHA1 0

/* ECDSA is significantly faster than RSA or DSS. Compiling in ECC
 * code (either ECDSA or ECDH) increases binary size - around 30kB
 * on x86-64.
 * See: ECDSA_PRIV_FILENAME  */
#define DROPBEAR_ECDSA 0

/* Ed25519 is faster than ECDSA. Compiling in Ed25519 code increases
 * binary size - around 7,5kB on x86-64.
 * See: ED25519_PRIV_FILENAME  */
#define DROPBEAR_ED25519 0

/* Allow U2F security keys for public key auth, with
 * sk-ecdsa-sha2-nistp256@openssh.com or sk-ssh-ed25519@openssh.com keys.
 * The corresponding DROPBEAR_ECDSA or DROPBEAR_ED25519 also needs to be set.
 * This is currently server-only. */
#define DROPBEAR_SK_KEYS 0

/* Key exchange algorithm.

 * group14_sha1 - 2048 bit, sha1
 * group14_sha256 - 2048 bit, sha2-256
 * group16 - 4096 bit, sha2-512
 * group1 - 1024 bit, sha1
 * curve25519 - elliptic curve DH
 * ecdh - NIST elliptic curve DH (256, 384, 521)
 *
 * group1 is too small for security though is necessary if you need
     compatibility with some implementations such as Dropbear versions < 0.53
 * group14 is supported by most implementations.
 * group16 provides a greater strength level but is slower and increases binary size
 * curve25519 and ecdh algorithms are faster than non-elliptic curve methods
 * curve25519 increases binary size by ~2,5kB on x86-64
 * including either ECDH or ECDSA increases binary size by ~30kB on x86-64

 * Small systems should generally include either curve25519 or ecdh for performance.
 * curve25519 is less widely supported but is faster
 */
#define DROPBEAR_DH_GROUP14_SHA1 0
#define DROPBEAR_DH_GROUP14_SHA256 0
#define DROPBEAR_DH_GROUP16 0
#define DROPBEAR_CURVE25519 1
#define DROPBEAR_ECDH 0
#define DROPBEAR_DH_GROUP1 0

/* Whether to print the message of the day (MOTD). */
#define DO_MOTD 0

/* ~/.ssh/authorized_keys authentication.
 * You must define DROPBEAR_SVR_PUBKEY_AUTH in order to use plugins. */
#define DROPBEAR_SVR_PUBKEY_AUTH 0

/* Whether to take public key options in
 * authorized_keys file into account */
#define DROPBEAR_SVR_PUBKEY_OPTIONS 0

/* Client authentication options */
#define DROPBEAR_CLI_PASSWORD_AUTH 1
#define DROPBEAR_CLI_PUBKEY_AUTH 0

/* The default path. This will often get replaced by the shell */
#define DEFAULT_PATH "/home/bin:/usr/bin:/bin"
#define DEFAULT_ROOT_PATH "/home/bin:/usr/sbin:/usr/bin:/sbin:/bin"


#endif /* DROPBEAR_LOCAL_OPTIONS_H */
