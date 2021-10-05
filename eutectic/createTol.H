const dictionary& get_Tol_from_this = mesh.solutionDict().subDict("Tol_is_defined_here");

scalar Tol(readScalar(get_Tol_from_this.lookup("Tol")));
