void mergeSort2(int arr[], const int size)
{
	int l, r; // left and right indices for comparisons

	int * scratch = new  int[size]; // a scratch array to hold values while sorting 

	// double the 'partitionSize' each iteration until it reaches 'size'
	for (int partitionSize = 2; partitionSize < size; partitionSize <<= 1)
	{	
		// for each partition that fits in 'size'
		for (int i = 0; i < size; i += partitionSize)
		{
			l = 0; // initialize to the beginning of the firt half of the partition
			r = partitionSize / 2; // initialize to the second half of the partition

			// for each element in the partition
			for (int j = 0; j < partitionSize; j++)
			{
				// if the element from the left half is less than or equal to the element from the right half
				// or if the right half is empty and the right side is not empty
				if ((arr[i + l] <= arr[i + r] || r == partitionSize) && l != partitionSize / 2 )
				{
					// if the element is less than or equal to, or if the other half is empty
					// then add the element to the scratch array
					scratch[j] = arr[i + l]; 

					l++; // increment the left index
				}
				else
				{
					// if the element is greater than, or if the other half is empty
					// then add the element to the scratch array
					scratch[j] = arr[i + r];

					r++; // increment the right index
				}
			}

			// transfer the elements from the scratch array back into the original
			for (int j = 0; j < partitionSize; j++)
			{
				arr[i + j] = scratch[j];
			}
		}
	}

	// no memory leaks!
	delete[] scratch;
}