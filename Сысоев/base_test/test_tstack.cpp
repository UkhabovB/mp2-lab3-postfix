#include "stack.h"
#include <gtest.h>


class TStackTest : public ::testing::Test 
{
protected:
	TStack<int> *stack;
	TStackTest() : stack(NULL) {};

	void CreateStack(int _size)  
	{
		stack = new TStack<int>(_size);
	}

	void SetUpFullStack()
	{
		for(int i = 0; i < stack->getSize();i++)
			stack->push(i);
	}

	~TStackTest()
	{
		delete stack;
	}
};

TEST_F(TStackTest,can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> stack(10));
}

TEST_F(TStackTest, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> stack(-10)); 
}

TEST_F(TStackTest, cant_create_stack_with_too_large_length)
{
	ASSERT_ANY_THROW(TStack<int> stack(MAX_STACK_SIZE + 1)); 
}
TEST_F(TStackTest,can_get_stack_size)
{
	CreateStack(10);

	EXPECT_EQ(stack->getSize() , 10);
}

TEST_F(TStackTest,can_get_stack_top)
{
	CreateStack(10);

	stack->push(3);

	EXPECT_EQ(stack->getTop() , 0);
}

TEST_F(TStackTest,can_identify_the_full_stack)
{
	CreateStack(10);

	SetUpFullStack();

	ASSERT_TRUE(stack->isFull());
}

TEST_F(TStackTest, can_identify_the_empty_stack)
{
	CreateStack(10);

	ASSERT_TRUE(stack->isEmpty());
}



TEST_F(TStackTest,can_push_elem)
{
	CreateStack(10);

	ASSERT_NO_THROW(stack->push(2));
}


TEST_F(TStackTest,can_pop_elem_with_not_empty_stack)
{
	CreateStack(10);

	SetUpFullStack();

	ASSERT_NO_THROW(stack->pop());
}


TEST_F(TStackTest,cannot_pop_elem_with_empty_stack)
{
	CreateStack(10);

	ASSERT_ANY_THROW(stack->pop());
}



TEST_F(TStackTest,can_push_elem_with_full_stack)
{
	CreateStack(10);

	SetUpFullStack();

	ASSERT_NO_THROW(stack->push(6));
}

TEST_F(TStackTest,change_size_when_reload_memory)
{
	CreateStack(5);

	SetUpFullStack();
	stack->push(5);

	EXPECT_EQ(15,stack->getSize());

}

