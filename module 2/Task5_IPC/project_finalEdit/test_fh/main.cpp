#include <gtest/gtest.h>
#include "fh.h"


TEST(Test_1, Reading_Pipe) {
    
    
    EXPECT_EQ(pipe_read(), -1);

}

TEST(Test_2, Writing_SharedMem) {
    
    
    EXPECT_EQ(sharedMem_write(), 0);

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
