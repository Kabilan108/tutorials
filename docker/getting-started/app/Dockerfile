# get base image
FROM node:18-alpine

# set (create) & cd to working directory
WORKDIR /app

# copy from current directory to working directory
COPY . .

# install dependencies
RUN yarn install --production

# run node with src/index.js as entrypoint
CMD ["node", "src/index.js"]
