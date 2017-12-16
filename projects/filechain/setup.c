/* ================================================= *
 * SETUP file:-------------------------------------- *
 * Creates folders for simulation (nodes)----------- *
 * and related registers (ledger.ldg and status.bin) *
 * ================================================= */

#include <stdio.h>
#include "./setlib.h"

#define README_FILE_NAME   "./simulation/readme.txt"
#define LEDGER_FILE_NAME   "./simulation/ledger.ldg"
#define LEDGER_DIR_NAME    "./simulation/"
#define MATRIX_DIR_NAME    "./simulation/matrix/"
#define NODE_1_DIR_NAME    "./simulation/matrix/node-1/"
#define NODE_1_STATUS_NAME "./simulation/matrix/node-1/status-1.bin"
#define NODE_2_DIR_NAME    "./simulation/matrix/node-2/"
#define NODE_2_STATUS_NAME "./simulation/matrix/node-2/status-2.bin"
#define NODE_3_DIR_NAME    "./simulation/matrix/node-3/"
#define NODE_3_STATUS_NAME "./simulation/matrix/node-3/status-3.bin"
#define NODE_4_DIR_NAME    "./simulation/matrix/node-4/"
#define NODE_4_STATUS_NAME "./simulation/matrix/node-4/status-4.bin"
#define NODE_5_DIR_NAME    "./simulation/matrix/node-5/"
#define NODE_5_STATUS_NAME "./simulation/matrix/node-5/status-5.bin"
#define NODE_1_LEDGER_NAME "./simulation/matrix/node-1/legder.ldg"
#define NODE_2_LEDGER_NAME "./simulation/matrix/node-2/legder.ldg"
#define NODE_3_LEDGER_NAME "./simulation/matrix/node-3/legder.ldg"
#define NODE_4_LEDGER_NAME "./simulation/matrix/node-4/legder.ldg"
#define NODE_5_LEDGER_NAME "./simulation/matrix/node-5/legder.ldg"
#define NODE_1_SIM_NAME    "./simulation/matrix/node-1/filechain.c"
#define NODE_2_SIM_NAME    "./simulation/matrix/node-2/filechain.c"
#define NODE_3_SIM_NAME    "./simulation/matrix/node-3/filechain.c"
#define NODE_4_SIM_NAME    "./simulation/matrix/node-4/filechain.c"
#define NODE_5_SIM_NAME    "./simulation/matrix/node-5/filechain.c"

int main(int argc, char *argv[])
{
	int errors;

	initSetup(&errors);

	createDir(LEDGER_DIR_NAME);
	createReadme(README_FILE_NAME, &errors);
	createLedger(LEDGER_FILE_NAME, &errors);
	createDir(MATRIX_DIR_NAME);
	createDir(NODE_1_DIR_NAME);
	createStatus(NODE_1_STATUS_NAME, &errors);
	createLedger(NODE_1_LEDGER_NAME, &errors);
	createSim(NODE_1_SIM_NAME, &errors);
	createDir(NODE_2_DIR_NAME);
	createStatus(NODE_2_STATUS_NAME, &errors);
	createLedger(NODE_2_LEDGER_NAME, &errors);
	createSim(NODE_2_SIM_NAME, &errors);
	createDir(NODE_3_DIR_NAME);
	createStatus(NODE_3_STATUS_NAME, &errors);
	createLedger(NODE_3_LEDGER_NAME, &errors);
	createSim(NODE_3_SIM_NAME, &errors);
	createDir(NODE_4_DIR_NAME);
	createStatus(NODE_4_STATUS_NAME, &errors);
	createLedger(NODE_4_LEDGER_NAME, &errors);
	createSim(NODE_4_SIM_NAME, &errors);
	createDir(NODE_5_DIR_NAME);
	createStatus(NODE_5_STATUS_NAME, &errors);
	createLedger(NODE_5_LEDGER_NAME, &errors);
	createSim(NODE_5_SIM_NAME, &errors);

	endSetup(&errors);

	return 0;
}
