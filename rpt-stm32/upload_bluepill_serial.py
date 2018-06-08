from os.path import join
from base64 import b64decode


from SCons.Script import DefaultEnvironment

env = DefaultEnvironment()
#
# Dump build environment (for debug)
# print env.Dump()

#

#env.Replace(UPLOADHEXCMD='"$UPLOADER" ' + b64decode(ARGUMENTS.get("CUSTOM_OPTION")) + ' --uploader --flags')

# print ARGUMENTS
env.Replace(
    UPLOADER=join("$PIOHOME_DIR", "packages",
                     "tool-stm32duino", "stm32flash", "stm32flash"),
    UPLOADCMD='$UPLOADER -R -i \'-rts,dtr,dtr,dtr,dtr,dtr,dtr,dtr,dtr,dtr,dtr,dtr,-dtr:rts,dtr,dtr,dtr,dtr,dtr,dtr,dtr,-dtr\' -w $SOURCE $UPLOAD_PORT '
)
# uncomment line below to see environment variables
# print ARGUMENTS
