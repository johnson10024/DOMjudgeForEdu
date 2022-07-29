#include <cstdio>
#include <cstdlib>

using namespace std;

FILE *inp, *out;
char EXE_PATH[100100];
char FILE_PATH[100100];
char command[100100];

void printUsage()
{
    fprintf(stderr,"Usage: \n");
    fprintf(stderr,"    ./gen_ans <directory> <exe> <num_of_data>\n");
	fprintf(stderr,"    ./gen_ans <directory> <exe> <num_from> <num_to>\n\n");

    fprintf(stderr,"        directory: Main directory of file\n");
    fprintf(stderr,"        exe: Answer generator(AC code) name\n");
    fprintf(stderr,"        num_of_data: Number of testcases\n");
    fprintf(stderr,"        num_from: Testcase starting index\n");
    fprintf(stderr,"        num_to: Testcase ending index\n\n");

    fprintf(stderr,"    Dir tree:\n");
    fprintf(stderr,"        main\n");
    fprintf(stderr,"          \\-exe\n");
    fprintf(stderr,"          |-data\\secret\n");
    fprintf(stderr,"           \\-1.in\n");
    fprintf(stderr,"           |-2.in\n");
    fprintf(stderr,"           |-...in\n");

}

int main(int argc, char **argv)
{
    if(argc < 4)
	{
		printUsage();
		return 0;
	}

	sprintf(command, "mkdir -p %s/data/secret", argv[1]);
	system(command);

	sprintf(EXE_PATH, "%s/%s", argv[1], argv[2]); //dir/exe
	sprintf(FILE_PATH, "%s/data/secret", argv[1]);	//dir/data

	int stat;
	int from, to;

	if(argc >= 5)
	{
		from = atoi(argv[3]);
		to = atoi(argv[4]);
	}
	else
	{
		from = 1;
		to = atoi(argv[3]);
	}
	
	for(int i = from; i <= to; i++)
	{
		sprintf(command, "%s < %s/%d.in > %s/%d.ans", EXE_PATH, FILE_PATH, i, FILE_PATH, i); // dir/exe < dir/data/i.in > dir/data/i.ans
		printf("%s...\n", command);

		stat = system(command);
		if(stat != 0) printf("create %d failed!\n", i);
	}

	return 0;
}
