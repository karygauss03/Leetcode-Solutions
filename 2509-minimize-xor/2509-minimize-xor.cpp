class Solution {
public:
    int minimizeXor(int sourceNum, int targetNum) {
        int minimizedResult = 0, targetBitCount = __builtin_popcount(targetNum), currentBitCount = 0, bitPosition = 31;

        while (currentBitCount < targetBitCount) {
            if (isBitSet(sourceNum, bitPosition) || (targetBitCount - currentBitCount > bitPosition)) {
                setBit(minimizedResult, bitPosition);
                currentBitCount++;
            }
            bitPosition--;
        }
        return minimizedResult;
    }

private:
    bool isBitSet(int num, int bitPos) { return num & (1 << bitPos); }
    void setBit(int &num, int bitPos) { num |= (1 << bitPos); }
};
