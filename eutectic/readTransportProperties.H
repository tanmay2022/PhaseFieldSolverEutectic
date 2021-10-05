   IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );

	//dimensionedScalar pi = constant::mathematical::pi;
        dimensionedScalar dimt(transportProperties.lookup("dimt"));    //diemsion of time
        dimensionedScalar dimx(transportProperties.lookup("dimx"));    //diemsion of position
        dimensionedScalar ms_alpha(transportProperties.lookup("ms_alpha"));      //slope liquidus
        dimensionedScalar ms_beta(transportProperties.lookup("ms_beta"));      //slope solidus
        //dimensionedScalar omega(transportProperties.lookup("omega"));  //relaxation coefficient for alpha (order parameter)
        //dimensionedScalar gamma(transportProperties.lookup("gamma"));           //Surface Energy
        //dimensionedScalar epsilon(transportProperties.lookup("epsilon"));       //Interface Width

        dimensionedScalar c_eq_liq(transportProperties.lookup("c_eq_liq"));           //composition of solid in equilibrium with liquid
        dimensionedScalar c_eq_alpha(transportProperties.lookup("c_eq_alpha"));          //composition of liquid in quilibrium with solid
        dimensionedScalar c_eq_beta(transportProperties.lookup("c_eq_beta"));            //equilibrium composition or avg composition of alloy

        //dimensionedScalar anti_trap(transportProperties.lookup("anti_trap"));           //antitrapping coefficient
        //dimensionedScalar diff_Sol(transportProperties.lookup("diff_Sol"));             //diffusivity in solid
        //dimensionedScalar diff_Liq(transportProperties.lookup("diff_Liq"));             //diffusivity in liquid

        dimensionedScalar G(transportProperties.lookup("G"));                           //thermal gradient
        dimensionedScalar v(transportProperties.lookup("v"));                           //velocity

        //dimensionedScalar delta_01(transportProperties.lookup("delta_01"));             //strength of anisotropy
        dimensionedScalar A(transportProperties.lookup("A"));
        dimensionedScalar D(transportProperties.lookup("D"));
        dimensionedScalar T_eut(transportProperties.lookup("T_eut"));                         //Melting Temp

        //dimensionedScalar noise_mag(transportProperties.lookup("noise_mag"));           //noise magnitude
        dimensionedScalar initial(transportProperties.lookup("initial"));               //constant value from temperature profile

        dimensionedScalar tau(transportProperties.lookup("tau"));
        dimensionedScalar gamma(transportProperties.lookup("gamma"));
        dimensionedScalar epsilon(transportProperties.lookup("epsilon"));
