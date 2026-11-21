/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    if (rowsCount * colsCount !== this.length) return [];

    const result = Array.from({ length: rowsCount }, () => new Array(colsCount));
    let idx = 0;

    for (let col = 0; col < colsCount; col++) {
        if (col % 2 === 0) {
            // even column: top -> bottom
            for (let row = 0; row < rowsCount; row++) {
                result[row][col] = this[idx++];
            }
        } else {
            // odd column: bottom -> top
            for (let row = rowsCount - 1; row >= 0; row--) {
                result[row][col] = this[idx++];
            }
        }
    }

    return result;
};

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */