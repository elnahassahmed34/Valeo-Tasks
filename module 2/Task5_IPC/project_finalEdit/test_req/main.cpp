#include <gtest/gtest.h>
#include "req.h"
#include <string>

TEST(Test_1, Writing_Pipe) {
    
    const char filePath = '../file'; // Use double quotes for string literals

    
    EXPECT_EQ(pipe_write(&filePath), -1);

}

TEST(Test_2, Reading_SharedMem) {
    
    
    EXPECT_EQ(sharedMem_read(), 0);

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
