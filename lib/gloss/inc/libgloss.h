/// @defgroup libgloss libgloss
/// @brief @ref libc : platform-specific wrappers
/// @ingroup libc
/// @{

/// @brief expand heap
extern char* sbrk(int nbytes);

/// @brief top of heap for @ref sbrk
extern char* heap_ptr;

/// @}
