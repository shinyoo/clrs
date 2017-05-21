//practice 4.1.5
//shame that i cant work this out and this piece of code is copied from http://clrs.skanev.com/04/01/05.html, awesome solution!
typedef struct {
    unsigned left;
    unsigned right;
    int sum;
} max_subarray;

max_subarray find_maximum_subarray(int A[], unsigned low, unsigned high) {
    max_subarray suffixes[high - low];

    suffixes[0].left = low;
    suffixes[0].right = low + 1;
    suffixes[0].sum = A[low];

	//the following is trickily clever!
    for (int i = low + 1; i < high; i++) {
    	//very simple and sharp judge: if the max sum ending with i-1 is negative , the max sum ending with i doesn't need to add it!
        if (suffixes[i - 1].sum < 0) {
            suffixes[i].left = i;
            suffixes[i].right = i + 1;
            suffixes[i].sum = A[i];
        } else {
            max_subarray *previous = &suffixes[i - 1];
        	// note the following has a passing-througth effect
            suffixes[i].left = previous->left;
            suffixes[i].right = i + 1;
            suffixes[i].sum = previous->sum + A[i];
        }
    }

    max_subarray *max = &suffixes[0];
    // now we just have to compare the maxes of subs ending with i, return the largest...
    for (int i = low + 1; i < high; i++) {
        if (max->sum < suffixes[i].sum) {
            max = &suffixes[i];
        }
    }

    return *max;
}