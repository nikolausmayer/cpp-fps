
/// System/STL
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
/// Local files
#include "fps.h"



int main(int argc, char** argv) {

  (void)argc;
  (void)argv;

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(33,33+10);

  FramesPerSecond::FPSEstimator fps;

  for ( unsigned int i = 0; i < 1000; ++i ) {
    std::cout << "FPS SAMPLE " << i << ": " << fps.FPS(3.f) << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(distribution(generator)));
    fps.AddSample();
  }

  return EXIT_SUCCESS;
}

