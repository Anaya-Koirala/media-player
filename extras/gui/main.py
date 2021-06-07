
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QInputDialog, QLineEdit, QFileDialog
from PyQt5.QtGui import QIcon
import os

class App(QWidget):

    def __init__(self):
        super().__init__()
        self.title = 'Media Player'
        self.left = 10
        self.top = 10
        self.width = 480
        self.height = 480
        self.initUI()
    
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        
        self.openFileNameDialog()
        exit()
    
    def openFileNameDialog(self):
        options = QFileDialog.Options()
        fileName, _ = QFileDialog.getOpenFileName(self,"Media Player", "","All Files (*);;Media Files (*.mp4)", options=options)
        if fileName:
            fileName="file://"+fileName
            print(fileName)
            os.system(f"./player -u '{fileName}'")  
    
    
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())