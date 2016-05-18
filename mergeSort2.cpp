void NewMergeSort(int arr[], const int size) {
	int l, r; // left and right indices for comparisons
	int * scratch = new  int[size]; // to hold values while sorting 
	int * swapArr;
	bool swapped = false;

	// double the 'partSize' each iteration until it reaches 'size'
	for (int partSize = 2; partSize < size * 2 - 1; partSize <<= 1) {

		// for each partition that fits in 'size'
		for (int i = 0; i < size; i += partSize){
			l = 0; // initialize to the beginning the partition

			r = partSize / 2; // initialize to the 2nd half of the partition
			// for each element in the partition
			for (int j = 0; j < partSize; j++) {
				// if the element from the left half is less
				// than or equal to the element from the right half
				// or if the right is empty and the left side is not empty
				if (i + r >= size || ((arr[i + l] <= arr[i + r] 
					|| r == partSize) && l != partSize / 2)){
					// if out of bounds, end the loop
					if (i + j >= size || i + l >= size) {
						break;
					}
					// if the element is less than or equal to,
					// or if the other half is empty
					// then add the element to the scratch array
					scratch[i + j] = arr[i + l];
					l++; // increment the left index
				} else {
					// if the element is greater than, 
					// or if the other half is empty
					// then add the element to the scratch array
					scratch[i + j] = arr[i + r];
					r++; // increment the right index
				}
			}
		}
		// instead of transferring each element individually, 
		// we swap the base pointers to the arrays
		swapArr = arr;
		arr = scratch;
		scratch = swapArr;
		swapped = !swapped;
	}
	if (swapped) {
		for (int j = 0; j < size; j++) {
			scratch[j] = arr[j];
		}
		delete[] arr; // no memory leaks!
	} else {
		delete[] scratch; // no memory leaks!
	}
}