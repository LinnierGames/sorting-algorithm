for i = 1 to A.length
	B[A[i]] = B[A[i]] + 1
for i = 2 to k
	B[i] = B[i] + B[i-1]
for i = A.length downto 1
	C[B[A[i]]] = A[i]
	B[A[i]] = B[A[i]] - 1