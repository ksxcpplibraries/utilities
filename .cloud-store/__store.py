

# Modules
from os import getcwd
from os.path import join, splitext
from utilities._sync_func import sync_dir
from utilities._clouds import _GoogleDrive, _OneDrive, _Dropbox


# Main
def main():

	source = getcwd()

	def __pycfilter(directory, child, action):
		return action and (child[-4:] == ".pyc" or ("\\.git" in directory) or ("\\.test-result" in directory))

	def __message(directory, child, action):
		print("\t" + ("copied " if action else "removed ") + (("./" + directory) if directory else ".") + "/" + child)

	def __sync(target, filter):
		print("\nDirectory: " + target)
		sync_dir(source, target, filter, __message)

	for cloud in [_GoogleDrive, _OneDrive, _Dropbox]:
		target = join(cloud, "__Stored/CPP_FILES/include")
		__sync(target, __pycfilter)

	print('\n')

main()


# The End
