/*
 * Copyright (c) 1996-2004 Barton P. Miller
 * 
 * We provide the Paradyn Parallel Performance Tools (below
 * described as "Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 * 
 * This license is for research uses.  For such uses, there is no
 * charge. We define "research use" to mean you may freely use it
 * inside your organization for whatever purposes you see fit. But you
 * may not re-distribute Paradyn or parts of Paradyn, in any form
 * source or binary (including derivatives), electronic or otherwise,
 * to any other organization or entity without our permission.
 * 
 * (for other uses, please contact us at paradyn@cs.wisc.edu)
 * 
 * All warranties, including without limitation, any warranty of
 * merchantability or fitness for a particular purpose, are hereby
 * excluded.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * Even if advised of the possibility of such damages, under no
 * circumstances shall we (or any other person or entity with
 * proprietary rights in the software licensed hereunder) be liable
 * to you or any third party for direct, indirect, or consequential
 * damages of any character regardless of type of action, including,
 * without limitation, loss of profits, loss of use, loss of good
 * will, or computer failure or malfunction.  You agree to indemnify
 * us (and any other person or entity with proprietary rights in the
 * software licensed hereunder) for any and all liability it may
 * incur to third parties resulting from your use of Paradyn.
 */

// $Id: test1_6.C,v 1.1 2008/10/30 19:19:48 legendre Exp $
/*
 * #Name: test1_6
 * #Desc: Mutator Side - Arithmetic Operators
 * #Arch: all
 * #Dep: 
 */

#include "BPatch.h"
#include "BPatch_Vector.h"
#include "BPatch_thread.h"
#include "BPatch_snippet.h"

#include "test_lib.h"
#include "dyninst_comp.h"

class test1_6_Mutator : public DyninstMutator {
	virtual test_results_t executeTest();
};

extern "C" DLLEXPORT  TestMutator *test1_6_factory() 
{
	return new test1_6_Mutator();
}

//
// Start Test Case #6 - mutator side (arithmetic operators)
//

test_results_t test1_6_Mutator::executeTest() 
{
	// Find the entry point to the procedure "func6_2"
	const char *funcName = "test1_6_func2";
	BPatch_Vector<BPatch_function *> found_funcs;
	if ((NULL == appImage->findFunction(funcName, found_funcs))
			|| !found_funcs.size()) 
	{
		logerror("    Unable to find function %s\n", funcName);
		return FAILED;
	}

	if (1 < found_funcs.size()) 
	{
		logerror("%s[%d]:  WARNING  : found %d functions named %s.  Using the first.\n", 
				__FILE__, __LINE__, found_funcs.size(), funcName);
	}

	BPatch_Vector<BPatch_point *> *point6_1 = found_funcs[0]->findPoint(BPatch_entry);  

	if (!point6_1 || ((*point6_1).size() == 0)) 
	{
		logerror("Unable to find entry point to \"%s\".\n", funcName);
		return FAILED;
	}

	const char *funcName2 = "test1_6_func1";
	BPatch_Vector<BPatch_function *> found_funcs2;

	if ((NULL == appImage->findFunction(funcName2, found_funcs2)) 
			|| !found_funcs2.size()) 
	{
		logerror("    Unable to find function %s\n", funcName2);
		return FAILED;
	}

	if (1 < found_funcs2.size()) 
	{
		logerror("%s[%d]:  WARNING  : found %d functions named %s.  Using the first.\n", 
				__FILE__, __LINE__, found_funcs2.size(), funcName2);
	}

	BPatch_Vector<BPatch_point *> *point6_2 = found_funcs2[0]->findPoint(BPatch_subroutine);  

	if (!point6_2 || ((*point6_2).size() == 0)) 
	{
		logerror("Unable to find subroutine points in \"%s\".\n", funcName2);
		return FAILED;
	}

	BPatch_variableExpr *expr6_1, *expr6_2, *expr6_3, *expr6_4, *expr6_5, *expr6_6,
						*expr6_1a, *expr6_2a, *expr6_3a, *expr6_4a, *expr6_5a, *expr6_6a,
						*constVar1, *constVar2, *constVar3, *constVar5, *constVar6,
						*constVar10, *constVar60, *constVar64, *constVar66, *constVar67;

	expr6_1 = findVariable(appImage, "test1_6_globalVariable1", point6_2);
	expr6_2 = findVariable(appImage, "test1_6_globalVariable2", point6_2);
	expr6_3 = findVariable(appImage, "test1_6_globalVariable3", point6_2);
	expr6_4 = findVariable(appImage, "test1_6_globalVariable4", point6_2);
	expr6_5 = findVariable(appImage, "test1_6_globalVariable5", point6_2);
	expr6_6 = findVariable(appImage, "test1_6_globalVariable6", point6_2);
	expr6_1a = findVariable(appImage, "test1_6_globalVariable1a", point6_2);
	expr6_2a = findVariable(appImage, "test1_6_globalVariable2a", point6_2);
	expr6_3a = findVariable(appImage, "test1_6_globalVariable3a", point6_2);
	expr6_4a = findVariable(appImage, "test1_6_globalVariable4a", point6_2);
	expr6_5a = findVariable(appImage, "test1_6_globalVariable5a", point6_2);
	expr6_6a = findVariable(appImage, "test1_6_globalVariable6a", point6_2);

	constVar1 = findVariable(appImage, "test1_6_constVar1", point6_2);
	constVar2 = findVariable(appImage, "test1_6_constVar2", point6_2);
	constVar3 = findVariable(appImage, "test1_6_constVar3", point6_2);
	constVar5 = findVariable(appImage, "test1_6_constVar5", point6_2);
	constVar6 = findVariable(appImage, "test1_6_constVar6", point6_2);
	constVar10 = findVariable(appImage, "test1_6_constVar10", point6_2);
	constVar60 = findVariable(appImage, "test1_6_constVar60", point6_2);
	constVar64 = findVariable(appImage, "test1_6_constVar64", point6_2);
	constVar66 = findVariable(appImage, "test1_6_constVar66", point6_2);
	constVar67 = findVariable(appImage, "test1_6_constVar67", point6_2);

	if (!expr6_1 || !expr6_2 || !expr6_3 || !expr6_4 ||
			!expr6_5 || !expr6_6 || !expr6_1a || !expr6_2a || !expr6_3a ||
			!expr6_4a || !expr6_5a || !expr6_6a) 
	{
		logerror("**Failed** test #6 (arithmetic operators)\n");
		logerror("    Unable to locate one of test1_6_globalVariable?\n");
		return FAILED;
	}

	if (!constVar1 || !constVar2 || !constVar3 || !constVar5 ||
			!constVar6 || !constVar10 || !constVar60 || !constVar64 || 
			!constVar66 || !constVar67) 
	{
		logerror("**Failed** test #6 (arithmetic operators)\n");
		logerror("    Unable to locate one of constVar?\n");
		return FAILED;
	}

	BPatch_Vector<BPatch_snippet*> vect6_1;

	// test1_6_globalVariable1 = 60 + 2
	BPatch_arithExpr arith6_1 (BPatch_assign, *expr6_1,
			BPatch_arithExpr(BPatch_plus,BPatch_constExpr(60), BPatch_constExpr(2)));
	vect6_1.push_back(&arith6_1);

	// test1_6_globalVariable2 = 64 - 1
	BPatch_arithExpr arith6_2 (BPatch_assign, *expr6_2, 
			BPatch_arithExpr(BPatch_minus,BPatch_constExpr(64),BPatch_constExpr(1)));
	vect6_1.push_back(&arith6_2);

	// test1_6_globalVariable3 = 553648128 / 25165824 = 22
	//    - make these big constants to test loading constants larger than
	//      small immediate - jkh 6/22/98

	BPatch_arithExpr arith6_3 (BPatch_assign, *expr6_3, BPatch_arithExpr(
				BPatch_divide,BPatch_constExpr(553648128),BPatch_constExpr(25165824)));
	vect6_1.push_back(&arith6_3);

	// test1_6_globalVariable4 = 67 / 3
	BPatch_arithExpr arith6_4 (BPatch_assign, *expr6_4, BPatch_arithExpr(
				BPatch_divide,BPatch_constExpr(67),BPatch_constExpr(3)));
	vect6_1.push_back(&arith6_4);
	// test1_6_globalVariable5 = 6 * 5
	BPatch_arithExpr arith6_5 (BPatch_assign, *expr6_5, BPatch_arithExpr(
				BPatch_times,BPatch_constExpr(6),BPatch_constExpr(5)));
	vect6_1.push_back(&arith6_5);

	// test1_6_globalVariable6 = 10,3
	BPatch_arithExpr arith6_6 (BPatch_assign, *expr6_6, 
			BPatch_arithExpr(BPatch_seq,BPatch_constExpr(10),BPatch_constExpr(3)));
	vect6_1.push_back(&arith6_6);

	// test1_6_globalVariable1a = 60 + 2
	BPatch_arithExpr arith6_1a (BPatch_assign, *expr6_1a, 
			BPatch_arithExpr(BPatch_plus, *constVar60, *constVar2));
	vect6_1.push_back(&arith6_1a);

	// test1_6_globalVariable2a = 64 - 1
	BPatch_arithExpr arith6_2a (BPatch_assign, *expr6_2a, 
			BPatch_arithExpr(BPatch_minus, *constVar64, *constVar1));
	vect6_1.push_back(&arith6_2a);

	// test1_6_globalVariable3a = 66 / 3
	BPatch_arithExpr arith6_3a (BPatch_assign, *expr6_3a, BPatch_arithExpr(
				BPatch_divide, *constVar66, *constVar3));
	vect6_1.push_back(&arith6_3a);

	// test1_6_globalVariable4a = 67 / 3
	BPatch_arithExpr arith6_4a (BPatch_assign, *expr6_4a, BPatch_arithExpr(
				BPatch_divide, *constVar67, *constVar3));
	vect6_1.push_back(&arith6_4a);

	// test1_6_globalVariable5a = 6 * 5
	BPatch_arithExpr arith6_5a (BPatch_assign, *expr6_5a, BPatch_arithExpr(
				BPatch_times, *constVar6, *constVar5));
	vect6_1.push_back(&arith6_5a);

	// test1_6_globalVariable6a = 10,3
	// BPatch_arithExpr arith6_6a (BPatch_assign, *expr6_6a, *constVar3);
	//	BPatch_arithExpr(BPatch_seq, *constVar10, BPatch_constExpr(3)));
	BPatch_arithExpr arith6_6a (BPatch_assign, *expr6_6a,
			BPatch_arithExpr(BPatch_seq, *constVar10, *constVar3));
	vect6_1.push_back(&arith6_6a);

	checkCost(BPatch_sequence(vect6_1));
	appAddrSpace->insertSnippet( BPatch_sequence(vect6_1), *point6_1);

	return PASSED;
}