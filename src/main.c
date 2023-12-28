#include <stdio.h>
#include "cpuinfo.h"
int main(void){
	reg_struct registers;
	cpuid cpuinfo;
	load_struct(&cpuinfo, &registers);

	puts("************* BASIC CPUID INFO *************************************\n");
	printf("Maximum Input Value for Basic CPUID Information:	%d\n", cpuinfo.basic_info.maximum_value);
	printf("Vendor Identification String:				%s\n", (char *)&cpuinfo.basic_info.string);
	printf("Stepping ID:						%d\n", cpuinfo.version_information.stepping_id);
	printf("Model:							0x%x\n", cpuinfo.version_information.model);
	printf("Family ID:						0x%x\n", cpuinfo.version_information.family_id);
	printf("Processor Type:						%d\n", cpuinfo.version_information.processor_type);
	printf("Extended Model ID:					%d\n", cpuinfo.version_information.extended_model_id);
	printf("Extended Family ID:					%d\n", cpuinfo.version_information.processor_type);
	return 0;
}
