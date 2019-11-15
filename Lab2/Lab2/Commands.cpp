#include "CommandMaker.h"

static CommandMaker<Sort> sortMaker("sort");
static CommandMaker<Readfile> readfileMaker("readfile");
static CommandMaker<Writefile> writefileMaker("writefile");
static CommandMaker<Grep> grepMaker("grep");
static CommandMaker<Replace> replaceMaker("replace");