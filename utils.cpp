#include "utils.h"
#include<stdlib.h>

using namespace std;
long random_at_most(long max)
{	
	unsigned long
		// max <= RAND_MAX < ULONG_MAX, so this is okay.
		num_bins = (unsigned long)max + 1,
		num_rand = (unsigned long)RAND_MAX + 1,
		bin_size = num_rand / num_bins,
		defect = num_rand % num_bins;
	long x;
	do {
		x = rand();
	}
	// This is carefully written not to overflow
	while (num_rand - defect <= (unsigned long)x);
	// Truncated division is intentional
		return x / bin_size;
}


unsigned int rand_interval(unsigned int min, unsigned int max)
{
	unsigned int r;
	const unsigned int range = 1 + max - min;
	const unsigned int buckets = RAND_MAX / range;
	const unsigned int limit = buckets * range;

	/* Create equal size buckets all in a row, then fire randomly towards
	 * the buckets until you land in one of them. All buckets are equally
	 * likely. If you land off the end of the line of buckets, try again. */
	do
	{
		r = rand();
	} while (r >= limit);

	return min + (r / buckets);
}