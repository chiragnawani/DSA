class Solution(object):
    def isValidSudoku(self, board):
        def checkduplicate(list1):
            seen = []
            duplicate = []
            for item in list1:
                if item == ".":
                    continue
                if item not in seen:
                    seen.append(item)
                else:
                    duplicate.append(item)
            if(duplicate):
                return True
            else:
                return False
        valid = True
        count = 0
        for row in board:
            if(checkduplicate(row)):
                print(True)
                count = count +1
            else:
                print(False)
#column
        for i in range(9):
            clist = []
            for row in board:
                clist.append(row[i])
            print(clist)
            if(checkduplicate(clist)):
                print(True)
                count = count+1
            else:
                print(False)
        blist = []
        i = 0
        while i<3:
            j=0
            while j<3:
                blist.append(board[i][j])
                j=j+1
            i=i+1

        elist = []
        for row in range(0,9,3):
            for column in range(0,9,3):
                elist = []
                i = row
                while i < row + 3:
                    j = column
                    while j< column +3:
                        elist.append(board[i][j])
                        j = j + 1
                    i = i +  1      
                print(elist)
                if(checkduplicate(elist)):
                    print(True)
                    count = count + 1
                else:
                    print(False)
        if count:
            return False
        else:
            return True