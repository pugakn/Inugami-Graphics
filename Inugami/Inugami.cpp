#include <cstdlib>
#include "in_api.h"
int main() {
  Inugami::GraphicsAPI app;
  
  try {
  app.Run();
    
  }
  catch (const std::exception& e) {
     std::cerr << e.what() << std::endl;
     return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}




