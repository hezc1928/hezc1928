import random
n = 3

  

def rand_lower():
    return chr(random.randint(ord('a'), ord('z')))


def random_value(dat):
    for i in range(n):
        for j in range(n):
            dat[i][j] = rand_lower()
            # dat[i][j]=random.randint(0,10)
            # numerical version
    return dat


def make_two_dimsion_list(n):
    dat = []
    for i in range(n):
        dat.append([])
        for j in range(n):
            dat[i].append(0)
    return dat


def two2one(dat):
    one_dim = []
    for i in range(n):
        for j in range(n):
            one_dim.append(dat[i][j])
    return one_dim


# make dict of letter
def make_dict(letter):
    dic = {}
    for i in range(26):
        dic[chr(i+97)] = letter[i]
    return dic


dat2 = make_two_dimsion_list(n)
random_value(dat2)
print(dat2)

dat1 = [0]*(n*n)
dat1 = two2one(dat2)
print(dat1)

letter = [0]*26
for a in range(n*n):
    letter[ord(dat1[a])-97] += 1
print(letter)

dic = make_dict(letter)
print(dic)

