#include <stdio.h>
#include "cpuinfo.h"
int main(void){
	load_struct(&cpuinfo, &registers);

	puts("************* BASIC CPUID INFO *************************************\n");
	printf("Maximum Input Value for Basic CPUID Information:	%d\n", cpuinfo.basic_info.maximum_value);
	printf("Vendor Identification String:				%s\n", (char *)&cpuinfo.basic_info.string);
	printf("Stepping ID:						%d\n", cpuinfo.version_information.stepping_id);
	printf("Model:							%d\n", cpuinfo.version_information.model);
	printf("Family ID:						0x%x\n", cpuinfo.version_information.family_id);
	return 0;
}
