/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    laplacianFoam

Description
    Solves a simple Laplace equation, e.g. for thermal diffusion in a solid.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "fvOptions.H"
#include "simpleControl.H"
#include "Random.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"

    #include "createTime.H"
    #include "createMesh.H"

    simpleControl simple(mesh);

    #include "createFields.H"
    #include "createTol.H"
    //volScalarField T = 0.0*mu;
    //volScalarField B_alpha = 0.0*mu;
    //volScalarField B_beta = 0.0*mu;
    //volScalarField D_alpha = 0.0*mu;
    //volScalarField D_beta = 0.0*mu;
    int iter_num = 0;
    
    T = G*( (1/dimx)* mesh.C().component(vector::X)) + initial;// - v*runTime.value()) + initial;
    //T = T_eut;d

    //free energy parameters

    dimensionedScalar B_alpha = 2.0*A*(c_eq_liq - c_eq_alpha);
    dimensionedScalar B_beta  = 2.0*A*(c_eq_liq - c_eq_beta );
    dimensionedScalar B_liq  =  0.0;

    volScalarField D_alpha = A*(- c_eq_liq + c_eq_alpha)*(c_eq_liq + c_eq_alpha + 2.0*(T - T_eut)/ms_alpha);
    volScalarField D_beta =  A*(- c_eq_liq + c_eq_beta )*(c_eq_liq + c_eq_beta  + 2.0*(T - T_eut)/ms_beta );
    volScalarField D_liq  ("D_liq", 0.*mu);

    //dimensionedScalar tau_alpha_beta = epsilon * (- c_eq_beta + c_eq_alpha) * (- c_eq_beta + c_eq_alpha) * 0.2 / (  D * 1/(2*A)    );
    //dimensionedScalar tau_alpha_liq = epsilon * (- c_eq_liq + c_eq_alpha) * (- c_eq_liq + c_eq_alpha) * 0.2 / (  D * 1/(2*A)    );
    //dimensionedScalar tau_beta_liq = epsilon * (- c_eq_beta + c_eq_liq) * (- c_eq_beta + c_eq_liq) * 0.2 / (  D * 1/(2*A)    );
    
    
            
while (runTime.loop())
    {
        Info<< "Time = " << runTime.timeName() << nl << endl;
               
          while (simple.correctNonOrthogonal())
        {
            #include "createTol.H"
            #include "phi_abl_antiT.H"
            
        }


        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
        runTime.write();
    }
    
    Info<< "End\n" << endl;
    Info<< "Total time taken\n" << endl;
    Info<< runTime.elapsedClockTime() << endl;

    return 0;
}
