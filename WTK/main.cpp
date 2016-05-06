// ***********************************************************************
// Assembly         : 
// Author           : yajunw
// Created          : 05-11-2015
//
// Last Modified By : yajunw
// Last Modified On : 05-11-2015
// ***********************************************************************
// <copyright file="WTK.cpp" company="SJTU">
//     Copyright (c) SJTU. All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************

# include <cstdlib>
# include <cstdio>
# include <FL/Fl.H>
# include "WtkApp.h"

// # define RUN_TEST

/// <summary>
/// Mains the specified argc.
/// </summary>
/// <param name="argc">The argc.</param>
/// <param name="argv">The argv.</param>
/// <returns>int.</returns>
int main(int argc, char **argv)
{
    Fl::get_system_colors();

# ifdef RUN_TEST
    WTK_Test* test = new WTK_Test();
    test->Run(true, "..\\..\\zlts\\out.log");
    delete test;
# endif

    WtkApp *app = new WtkApp();

	return Fl::run();
}
