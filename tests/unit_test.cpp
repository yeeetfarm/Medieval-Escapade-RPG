#include "gtest/gtest.h"

#include "../src/character.hpp"
#include "../src/attack.hpp"

#include "warrior_test.hpp"
#include "archer_test.hpp"
#include "mage_test.hpp"

#include "assassin_test.hpp"

#include "enemy_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
