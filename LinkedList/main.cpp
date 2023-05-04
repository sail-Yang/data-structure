#include "LinkedList.h"

int main(int argc, char const *argv[])
{
	LinkedList L;
	HeadInsert(L);
	L = deleteDuplicates(L);
	PrintList(L);
	return 0;
}
