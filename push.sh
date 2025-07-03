git pull origin main 

files=""
for file in "src/*/"*; do
 files+="${file} "
done

git add ${files} make.sh push.sh README.md 

echo "Message:"
read message

git commit -m "${message}"
git push origin main
