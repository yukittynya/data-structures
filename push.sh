git pull origin main 
git add .

echo "Message:"
read message

git commit -m "${message}"
git push origin main
