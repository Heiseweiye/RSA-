#include "rsa.h"

#define RSA_DGB 0

mpz_class RSA::randbits(int bits) //base = 2
{
	gmp_randclass a(gmp_randinit_default);
	a.seed(rand());
	mpz_class l(bits);
	return a.get_z_bits(l);
}

inline mpz_class RSA::randprime(int bits)
{
	mpz_class a = randbits(bits);
	mpz_class ret;
	mpz_nextprime(ret.get_mpz_t(), a.get_mpz_t());
	return ret;
}

void RSA::createKey(mpz_class &n, mpz_class &e, mpz_class &d, const int nbits, int ebits = 16)
{
	if (nbits / 2 <= ebits) {
		ebits = nbits / 2;
	}
	mpz_class p = randprime(nbits / 2);
	mpz_class q = randprime(nbits / 2);
	n = q*p;
	mpz_class fn = (p - 1)*(q - 1);
	mpz_class gcd;
	do{
		e = randprime(ebits);
		mpz_gcd(gcd.get_mpz_t(), e.get_mpz_t(), fn.get_mpz_t());
	} while (gcd != 1);
	mpz_gcdext(p.get_mpz_t(), d.get_mpz_t(), q.get_mpz_t(), e.get_mpz_t(), fn.get_mpz_t());
}

inline mpz_class RSA::encrypt(const mpz_class &m, const mpz_class &e, const mpz_class &n)
{
	mpz_class ret;
	mpz_powm(ret.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
	return ret;
}

inline mpz_class RSA::decrypt(const mpz_class &c, const mpz_class &d, const mpz_class &n)
{
	return encrypt(c, d, n);
}





RSA::RSA()
{

}
RSA::~RSA()
{

}
void RSA::generateKey(int nbits, int ebits = 16)
{
	createKey(key_n, key_e, key_d, nbits, ebits);
}


void RSA::getKey(KeyType type, string &ed, string &sn)
{
	if (type == PublicKey)
	{
		ed = key_e.get_str(16);
		sn = key_n.get_str(16);
	}
	else
	{
		ed = key_d.get_str(16);
		sn = key_n.get_str(16);
	}
}
void RSA::setKey(KeyType type, string &ed, string &sn)
{
	if (type == PublicKey)
	{

		key_e.set_str(ed.c_str(), 16);
		key_n.set_str(sn.c_str(), 16);
	}
	else
	{
		key_d.set_str(ed.c_str(), 16);
		key_n.set_str(sn.c_str(), 16);
	}
}

string RSA::Encrypt(string in, int base)
{

	mpz_class m;
	m.set_str(in.c_str(), base);


	mpz_class c;
	c = encrypt(m, key_e, key_n);
	return c.get_str(base);
}

string RSA::Decrypt(string in, int base)
{

	mpz_class m;
	m.set_str(in.c_str(), base);

	mpz_class c;
	c = decrypt(m, key_d, key_n);
	return c.get_str(base);
}



