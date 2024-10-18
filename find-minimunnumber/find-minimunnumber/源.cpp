#include <iostream>
using namespace std;//#include <iostream>: 这个指令是为了包含标准输入输出流库 (iostream)，使得你可以使用 cin、cout、cerr 等对象来处理输入和输出。只有在你需要进行输入输出操作时，才需要包含这个头文件。
int n, n2;
//这条指令告诉编译器使用标准命名空间(std)。标准库中的所有内容（如 cout、cin、vector 等）都位于 std 命名空间中。使用这条指令可以避免每次使用标准库对象时都需要加 std::前缀。比如：
int main()
{
	int array[1000];
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	int min = array[0];
		for (int i = 0; i < n; i++)
		{
			if (array[i] < min)
			{
				min=array[i];
			}
		}
	cout << min;
	return 0;
	
}