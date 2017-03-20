Question:
	Given n,how many structurally unqiue BST's that store values 1 .... n?

Solution:
	Cantalan algorithm
	fx(n) = fx(n - 1) * (4 * n - 2) / (n + 1)
