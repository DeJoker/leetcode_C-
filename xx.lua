-- print(#arg)
-- for i=1,#arg do
--     print(arg[i])
-- end


-- local res = 1
-- for i=1,#ARGV do
--     redis.call('setbit', KEYS[1], ARGV[i], 1);
-- end

-- local ret = 1
-- for i=1,#ARGV do
--     local bit = 1;
--     if bit == 0 then
--         ret = 0
--         redis.call('setbit', KEYS[1], ARGV[i], 1);
--     end
-- end
-- return ret

local ret = 1
for i=1,#ARGV do
    local bit = redis.call('getbit', KEYS[1], ARGV[i]);
    if bit ~= nil and bit ~= 1 then
        ret = 0
        redis.call('setbit', KEYS[1], ARGV[i], 1);
    end
end
return ret
