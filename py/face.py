import cv2
import numpy as np

file_path1 = "E:/cpp_project/py/image1.jpg"
file_path2 = "E:/cpp_project/py/image2.jpg"
img1 = cv2.imread(file_path1)
img2 = cv2.imread(file_path2)
morph_img = cv2.addWeighted(img1, 0.5, img2, 0.5, 0)
save_img = np.hstack((img1, morph_img, img2))
cv2.imwrite("E:\cpp_project\py\imagesave.jpg", save_img)
cv2.imshow("morph_img", save_img)
cv2.waitKey(0)
