#
# CS389\_HW3

Noah Koster

Part 1:

| Construction | Tests construction of cache | Pass |
| --- | --- | --- |
| Setting | Tests setting values in cache with set() function | Setting one - PassSetting two - Pass |
| Getting | Tests getting values in the cache and setting them using the get() and set() functions. Set two then get two tests behavior in getting null value. | Get one - PassSet two then get two - FailSet one, get one - Fail |
| Memory | Tests setting using set(), the space used function, space\_used(), and whether maxmem is adhered to correctly, along with whether the eviction policy sizes the array to maxmem correctly. Correct eviction policy is not to make the array smaller when trying to add element bigger then array. | Add values - PassAdd past maxmem - FailEviction - Fail |
| Deleting | Tests various ways of deleting values from the cache with the del() function. Deletes value then readds, and tests deleting two values. Delete two tests null behavior. | Re-add then delete - PassDelete two - Pass |
| Size | Tests retrieving the correct size of the cache and whether it can be resized correctly with the get() function | Retrieve Size - FailResizing - Fail |



Part two:

Abe:

1. No trouble at all compiling
2.

| Construction | Pass |
| --- | --- |
| Setting | Setting one - PassSetting two - Pass |
| Getting | Get one - PassSet two then get two - PassSet one, get one - Fail |
| Memory | Add values - PassAdd past maxmem - PassEviction - Fail |
| Deleting | Re-add then delete - PassDelete two - Pass  |
| Size | Retrieve Size - FailResizing - Fail |

Ryan:

1. No trouble compiling
2.

| Construction | Pass |
| --- | --- |
| Setting | Setting one - PassSetting two - Pass |
| Getting | Get one - PassSet two then get two - PassSet one, get one - Pass |
| Memory | Add values - PassAdd past maxmem - FailEviction - Pass |
| Deleting | Re-add then delete - PassDelete two - Pass  |
| Size | Retrieve Size - PassResizing - Pass |

All passed!

3.

David:

1. Trouble compiling with segmentation fault on unorderedmap::insert\_or\_assign(), had to recompile with static link to unordered\_map header file to avoid, but still failed failed deleting past null value in delete two.
2.

| Construction | Pass |
| --- | --- |
| Setting | Setting one - PassSetting two - Pass |
| Getting | Get one - PassSet two then get two - PassSet one, get one - Pass |
| Memory | Add values - PassAdd past maxmem - PassEviction - Pass |
| Deleting | Re-add then delete - PassDelete two - Fail  |
| Size | Retrieve Size - PassResizing - Pass |
