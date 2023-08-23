#include <gtest/gtest.h>
#include "../request/request.h"
#include "../file_handler/fh.h"

TEST(PipeWriteTest, SuccessfulRead) {
    int result = pipe_write();
    EXPECT_EQ(result, 0);
}

TEST(PipeReadTest, SuccessfulRead) {
    int result = pipe_read();
    EXPECT_EQ(result, 0);
}

TEST(SharedMemoryWrite_Test, SuccessfulRead) {
    int result = sharedMem_write();
    EXPECT_EQ(result, 0);
}

TEST(SharedMemoryRead_Test, SuccessfulRead) {
    int result = sharedMem_read();
    EXPECT_EQ(result, 0);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}