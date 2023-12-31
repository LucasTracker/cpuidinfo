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
	printf("Brand Index:						%d\n", cpuinfo.version_information.brand_index);
	printf("CLFLUSH Line Size:					%d (in bytes)\n", cpuinfo.version_information.clflush_line_size);
	printf("Maximum number addressable IDs:				%d\n", cpuinfo.version_information.max_number_ids);
	printf("Initial APIC ID:					%d\n\n\n", cpuinfo.version_information.initial_apic_id);

	printf("************* Features supported by CPU ****************************\n");
	printf("	 Feature				Supported   \n");
	printf("--------------------------------------------------------------------\n");
	printf("	  SSE3					  %s\n", cpuinfo.features_cpu.sse3 ? "Yes" : "No");
	printf("	  PCLMULQDQ				  %s\n", cpuinfo.features_cpu.pclmulqdq ? "Yes" : "No");
	printf("	  DTES64				  %s\n", cpuinfo.features_cpu.dtes64 ? "Yes" : "No");
	printf("	  MONITOR				  %s\n", cpuinfo.features_cpu.monitor ? "Yes" : "No");
	printf("	  DS_CPL				  %s\n", cpuinfo.features_cpu.ds_cpl ? "Yes" : "No");
	printf("	  VMX					  %s\n", cpuinfo.features_cpu.vmx ? "Yes" : "No");
	printf("	  SMX					  %s\n", cpuinfo.features_cpu.smx ? "Yes" : "No");
	printf("	  EIST					  %s\n", cpuinfo.features_cpu.eist ? "Yes" : "No");
	printf("	  TM2					  %s\n", cpuinfo.features_cpu.tm2 ? "Yes" : "No");
	printf("	  SSSE3					  %s\n", cpuinfo.features_cpu.ssse3 ? "Yes" : "No");
	printf("	  CNXT_ID				  %s\n", cpuinfo.features_cpu.cnxt_id ? "Yes" : "No");
	printf("	  SDBG					  %s\n", cpuinfo.features_cpu.sdbg ? "Yes" : "No");
	printf("	  FMA					  %s\n", cpuinfo.features_cpu.fma ? "Yes" : "No");
	printf("	  CMPXCHG16B				  %s\n", cpuinfo.features_cpu.cmpxchg16b ? "Yes" : "No");
	printf("	  XTPR					  %s\n", cpuinfo.features_cpu.xtpr ? "Yes" : "No");
	printf("	  PDCM					  %s\n", cpuinfo.features_cpu.pdcm ? "Yes" : "No");
	printf("	  PCID					  %s\n", cpuinfo.features_cpu.pcid ? "Yes" : "No");
	printf("	  DCA					  %s\n", cpuinfo.features_cpu.dca ? "Yes" : "No");
	printf("	  SSE4_1				  %s\n", cpuinfo.features_cpu.sse4_1 ? "Yes" : "No");
	printf("	  SSE4_2				  %s\n", cpuinfo.features_cpu.sse4_2 ? "Yes" : "No");
	printf("	  X2APIC				  %s\n", cpuinfo.features_cpu.x2apic ? "Yes" : "No");
	printf("	  MOVBE					  %s\n", cpuinfo.features_cpu.movbe ? "Yes" : "No");
	printf("	  POPCNT				  %s\n", cpuinfo.features_cpu.popcnt ? "Yes" : "No");
	printf("	  TSC_DEADLINE				  %s\n", cpuinfo.features_cpu.tsc_deadline ? "Yes" : "No");
	printf("	  AESNI					  %s\n", cpuinfo.features_cpu.aesni ? "Yes" : "No");
	printf("	  XSAVE					  %s\n", cpuinfo.features_cpu.xsave ? "Yes" : "No");
	printf("	  OSXSAVE				  %s\n", cpuinfo.features_cpu.osxsave ? "Yes" : "No");
	printf("	  AVX					  %s\n", cpuinfo.features_cpu.avx ? "Yes" : "No");
	printf("	  F16C					  %s\n", cpuinfo.features_cpu.f16c ? "Yes" : "No");
	printf("	  RDRAND				  %s\n", cpuinfo.features_cpu.rdrand ? "Yes" : "No");
	printf("	  FPU					  %s\n", cpuinfo.features_cpu.fpu ? "Yes" : "No");
	printf("	  VME					  %s\n", cpuinfo.features_cpu.vme ? "Yes" : "No");
	printf("	  DE					  %s\n", cpuinfo.features_cpu.de ? "Yes" : "No");
	printf("	  PSE					  %s\n", cpuinfo.features_cpu.pse ? "Yes" : "No");
	printf("	  TSC					  %s\n", cpuinfo.features_cpu.tsc ? "Yes" : "No");
	printf("	  MSR					  %s\n", cpuinfo.features_cpu.msr ? "Yes" : "No");
	printf("	  PAE					  %s\n", cpuinfo.features_cpu.pae ? "Yes" : "No");
	printf("	  MCE					  %s\n", cpuinfo.features_cpu.mce ? "Yes" : "No");
	printf("	  CX8					  %s\n", cpuinfo.features_cpu.cx8 ? "Yes" : "No");
	printf("	  APIC					  %s\n", cpuinfo.features_cpu.apic ? "Yes" : "No");
	printf("	  SEP					  %s\n", cpuinfo.features_cpu.sep ? "Yes" : "No");
	printf("	  MTRR					  %s\n", cpuinfo.features_cpu.mtrr ? "Yes" : "No");
	printf("	  PGE					  %s\n", cpuinfo.features_cpu.pge ? "Yes" : "No");
	printf("	  MCA					  %s\n", cpuinfo.features_cpu.mca ? "Yes" : "No");
	printf("	  CMOV					  %s\n", cpuinfo.features_cpu.cmov ? "Yes" : "No");
	printf("	  PAT					  %s\n", cpuinfo.features_cpu.pat ? "Yes" : "No");
	printf("	  PSE-36				  %s\n", cpuinfo.features_cpu.pse_36 ? "Yes" : "No");
	printf("	  PSN					  %s\n", cpuinfo.features_cpu.psn ? "Yes" : "No");
	printf("	  CLFSH					  %s\n", cpuinfo.features_cpu.clfsh ? "Yes" : "No");
	printf("	  DS					  %s\n", cpuinfo.features_cpu.ds ? "Yes" : "No");
	printf("	  ACPI					  %s\n", cpuinfo.features_cpu.acpi ? "Yes" : "No");
	printf("	  MMX					  %s\n", cpuinfo.features_cpu.mmx ? "Yes" : "No");
	printf("	  FXSR					  %s\n", cpuinfo.features_cpu.fxsr ? "Yes" : "No");
	printf("	  SSE					  %s\n", cpuinfo.features_cpu.sse ? "Yes" : "No");
	printf("	  SSE2					  %s\n", cpuinfo.features_cpu.sse2 ? "Yes" : "No");
	printf("	  SS					  %s\n", cpuinfo.features_cpu.ss ? "Yes" : "No");
	printf("	  HTT					  %s\n", cpuinfo.features_cpu.htt ? "Yes" : "No");
	printf("	  TM					  %s\n", cpuinfo.features_cpu.tm ? "Yes" : "No");
	printf("	  PBE					  %s\n", cpuinfo.features_cpu.pbe ? "Yes" : "No");

	return 0;
}
