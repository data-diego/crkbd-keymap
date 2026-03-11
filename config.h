#pragma once

// Enable split transport RPC so we can sync animation state to slave half
#define SPLIT_TRANSACTION_IDS_USER ANIM_SYNC

// Animation frame intervals
#define ANIM_FRAME_FAST 50   // non-repo anims (~20fps)
#define ANIM_FRAME_SLOW 100  // repo anims (~10fps)
