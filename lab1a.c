#include <stdio.h>
#include <stdlib.h>

typedef struct Rational {
	int numerator;
	int denumerator;
} Rational;

// Pass by reference, in this case there is little reason to not use value,
// but for future use, we might have a much larger struct in which it makes more sense.
void print_rational(const Rational* r) {
	printf("(%d + %di)\n", r->numerator, r->denumerator);
}

// Find the greates common divider, using Euclid's algorithm.
int gcd(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

// Modifiy the object itself, it might make more sense to create a new?
// But in most cases you prob don't need the original, and if you do, just copy it.
void reduce(Rational* r) {
	int g = gcd(r->numerator, r->denumerator);
	r->numerator /= g;
	r->denumerator /= g;
}

Rational addq(Rational* a, Rational* b) {
	Rational n;
	n.numerator = a->numerator + b->numerator;
	n.denumerator = a->denumerator + b->denumerator;
	return n;
}

Rational subq(Rational* a, Rational* b) {
	Rational n;
	n.numerator = a->numerator - b->numerator;
	n.denumerator = a->denumerator - b->denumerator;
	return n;
}

Rational mulq(Rational* a, Rational* b) {
	Rational n;
	n.numerator = a->numerator * b->numerator;
	n.denumerator = a->denumerator * b->denumerator;
	return n;
}

Rational divq(Rational* a, Rational* b) {
	Rational n;
	n.numerator = a->numerator / b->numerator;
	n.denumerator = a->denumerator / b->denumerator;
	return n;
}

void test(Rational* expected, Rational* got) {
	printf("Expected: ");
	print_rational(expected);

	printf("Got: ");
	print_rational(got);

	if (expected->numerator != got->numerator || expected->denumerator != got->denumerator) {
		printf("ERROR: Not matching\n");
	}

	printf("\n");
}

int main(int argc, char* argv[])
{
	Rational n1 = {10, 2};

	print_rational(&n1);
	reduce(&n1);
	print_rational(&n1);
	printf("\n");

	Rational r1 = {10, 5};
	Rational r2 = {5, 2};

	Rational expectedAdd = {15, 7};
	Rational add = addq(&r1, &r2);
	test(&expectedAdd, &add);

	Rational expectedSub = {5, 3};
	Rational sub = subq(&r1, &r2);
	test(&expectedSub, &sub);

	Rational expectedMul = {50, 10};
	Rational mul = mulq(&r1, &r2);
	test(&expectedMul, &mul);

	Rational expectedDiv = {2, 2};
	Rational div = divq(&r1, &r2);
	test(&expectedDiv, &div);

	return 0;
}
