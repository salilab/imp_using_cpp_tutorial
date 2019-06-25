/** \example core/simple.cpp

    Simple example of using the IMP C++ library.

    This should be equivalent to the first part of the Python example simple.py.
*/

#include <fstream>

#include <IMP.h>
#include <IMP/algebra.h>
#include <IMP/core.h>
#include <IMP/flags.h>

int main(int argc, char *argv[]) {
  IMP::setup_from_argv(argc, argv,
                       "Simple example of using the IMP C++ library.");

  IMP_NEW(IMP::Model, m, ());

  // Create two "untyped" particles
  IMP::ParticleIndex p1 = m->add_particle("p1");
  IMP::ParticleIndex p2 = m->add_particle("p2");

  // "Decorate" the particles with x,y,z attributes (point-like
  // particles)
  IMP::core::XYZ d1 = IMP::core::XYZ::setup_particle(m, p1);
  IMP::core::XYZ d2 = IMP::core::XYZ::setup_particle(m, p2);

  // Use some XYZ-specific functionality (set coordinates)
  d1.set_coordinates(IMP::algebra::Vector3D(10.0, 10.0, 10.0));
  d2.set_coordinates(IMP::algebra::Vector3D(-10.0, -10.0, -10.0));
  std::cout << d1 << " " << d2 << std::endl;

  return 0;
}
